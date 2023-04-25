#pragma once
#include "No_0_common.h"
using namespace std;

class No_3
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		int length = s.length();

		if (length<=0)
		{
			return 0;
		}
		if (1==length)
		{
			return 1;
		}
		string target = "";
		int targetStart = 0;
		int pos = 0;
		int index=0;
		int count = 0;
		int bestCount = 0;
		while (index<length)
		{
			pos = target.find(s[index]);
			if (pos != string::npos)
			{
				index = targetStart + pos + 1;
				target = "";
				targetStart = index;
				if (count>bestCount)
				{
					bestCount = count;
				}
				count = 0;
				continue;
			}
			target += s[index];
			++count;
			++index;
		}
		if (count>bestCount)
		{
			bestCount = count;
		}
		//cout << "target: " << target << endl;
		return bestCount;
	}

	int lengthOfLongestSubstring2(string s)
	{
		int length = s.length();
		if (length <= 0)
		{
			return 0;
		}
		bool array[256] = { 0 };
		int fast = 0, slow = 0;
		int bestLength = -1, currentLength = 0;

		while (fast<length)
		{
			if (false==array[s[fast]])
			{
				array[s[fast]] = true;
				++fast;
				++currentLength;
			}
			else
			{
				array[s[slow]] = false;
				++slow;
				--currentLength;
			}
			if (bestLength<currentLength)
			{
				bestLength = currentLength;
			}
		}

		return bestLength;
	}
};