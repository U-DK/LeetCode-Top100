#pragma once
#include "No_0_common.h"
#include <algorithm>

class No_14
{
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		int index=0;
		//string target = "";
		string shortest = strs[0];
		char c = 0;
		for (auto& str : strs)
		{
			if (str.size() < shortest.size())
			{
				shortest = str;
			}
		}
		while (index<shortest.size())
		{
			c = shortest[index];
			for (auto& str : strs)
			{
				if (str[index] != c)
				{
					c = 0;
					break;
				}
			}
			if (0 == c)
			{
				break;
			}
			++index;

		}
		return shortest.substr(0, index);
	}

	string longestCommonPrefix2(vector<string>& strs)
	{
		if (1==strs.size())
		{
			return strs[0];
		}
		int index = 0;
		sort(strs.begin(), strs.end());

		for (int i = 0; i != strs[0].size(); ++i)
		{
			if (strs[0][i] != strs[strs.size() - 1][i])
			{
				break;
			}
			++index;
		}
		return strs[0].substr(0, index);
	}
};