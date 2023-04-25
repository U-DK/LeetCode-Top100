#pragma once
#include "No_0_common.h"
#include <stack>

class 
{
public:
	bool isValid(string s) 
	{
		stack<char> charStack;
		for (auto& c : s)
		{
			if (charStack.empty() && (c == ')' || c == ']' || c == '}'))
			{
				return false;
			}
			if (c == '(' || c == '[' || c == '{')
			{
				charStack.push(c);
				continue;
			}
			if (!charStack.empty())
			{
				if (abs(c - charStack.top()) > 2 || abs(c - charStack.top()) <= 0)
				{
					return false;
				}
				if (abs(c - charStack.top()) <=2)
				{
					charStack.pop();
				}
			}

		}

		return charStack.empty();
	}
};