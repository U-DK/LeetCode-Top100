#pragma once
#include "No_0_common.h"

class No_5
{
public:
	string longestPalindrome(string s) 
	{
		if (1==s.size())
		{
			return s;
		}
		
		string ss = "";
		for (int i=0;i!=s.size();++i)
		{
			ss += s[i];
			ss += '#';
		}
		ss.erase(ss.size() - 1);
		cout << "ss: " << ss << endl;
		int length = ss.size();
		int midIndex = length / 2;
		int step = 1;
		string target = "";
		//target = ss[midIndex];
		vector<int> vec;
		vec.push_back(midIndex);
		while (!vec.empty())
		{
			midIndex = vec.back();
			vec.pop_back();
			step = 1;
			while (midIndex - step >= 0 && midIndex + step < ss.size())
			{
				if (ss[midIndex - step] == ss[midIndex + step])
				{
					if ('#' == ss[midIndex - step])
					{
						++step;
						continue;
					}
					if (target.size() < 2 * step + 1)
					{
						target = ss.substr(midIndex - step, 2 * step + 1);
						cout << "target: " << target << endl;
					}
					++step;
					//a#b#b
				}
				else
				{
					if (midIndex - 0 == ss.size() - 1 - midIndex)
					{
						vec.push_back(midIndex + 1);
						vec.push_back(midIndex - 1);
					}
					else if (midIndex - 0 > ss.size() - 1 - midIndex)
					{
						vec.push_back(midIndex + 1);
					}
					else
					{
						vec.push_back(midIndex - 1);
					}


					break;
				}

			}
		}
		if (target.empty())
		{
			ss = s[0];
			return ss;
		}
		ss = "";
		for (int i = 0; i != target.size(); ++i)
		{
			if ('#' == target[i])
			{
				continue;
			}
			ss += target[i];
		}
		return ss;

	}
};