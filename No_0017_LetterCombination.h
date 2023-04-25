#pragma once
#include "No_0_common.h"

class No_17
{
public:
	vector<string> letterCombinations(string digits) 
	{
		if (digits.size()<1)
		{
			return {};
		}

		if (digits.size() == 1)
		{
			return GetVecBasedOnNumber(digits);
		}
		vector<string> temp;
		vector<string> temp2;

		if (digits.size()>1)
		{
			temp = letterCombinations(digits.substr(0, digits.size() / 2));
			temp2 = letterCombinations(digits.substr(digits.size() / 2));
		}
		vector<string> ret;
		for (int i = 0; i != temp.size(); ++i)
		{
			for (int j = 0; j != temp2.size(); ++j)
			{
				ret.push_back(temp[i] + temp2[j]);
			}
		}
		return ret;

		
	}

	vector<string> GetVecBasedOnNumber(string& s)
	{
		char c = s[0];
		if (55 == c)
		{
			return { string(1,112),string(1,113) ,string(1,114) ,string(1,115) };
		}
		if (56 == c)
		{
			return { string(1,116),string(1,117) ,string(1,118) };
		}
		if (57 == c)
		{
			return { string(1,119),string(1,120) ,string(1,121) ,string(1,122) };
		}
		char temp = 97 + (c - 48 - 2) * 3;
		return {string(1,temp),string(1,temp+1) ,string(1,temp+2)};
	}

	
};