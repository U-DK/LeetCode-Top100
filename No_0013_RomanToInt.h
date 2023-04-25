#pragma once
#include "No_0_common.h"
#include <stack>

class No_13
{
public:
	int romanToInt(string s)
	{

		stack<char> charStack;
		int num = 0;
		for (int i = 0; i != s.size(); ++i)
		{
			if (!charStack.empty())
			{
				if (charStack.top() == 'I')
				{
					if (s[i] == 'V')
					{
						num += 4;
						charStack.pop();
						continue;
					}
					if (s[i] == 'X')
					{
						num += 9;
						charStack.pop();
						continue;
					}
					
				}
				if (charStack.top() == 'X')
				{
					if (s[i] == 'L')
					{
						num += 40;
						charStack.pop();
						continue;
					}
					if (s[i] == 'C')
					{
						num += 90;
						charStack.pop();
						continue;
					}
				}
				if (charStack.top() == 'C')
				{
					if (s[i] == 'D')
					{
						num += 400;
						charStack.pop();
						continue;
					}
					if (s[i] == 'M')
					{
						num += 900;
						charStack.pop();
						continue;
					}
				}
			}
			charStack.push(s[i]);
		}
		int temp = 0;
		while (!charStack.empty())
		{
			if ('I' == charStack.top())
			{
				temp = 1;
			}
			if ('V' == charStack.top())
			{
				temp = 5;
			}
			if ('X' == charStack.top())
			{
				temp = 10;
			}
			if ('L' == charStack.top())
			{
				temp = 50;
			}
			if ('C' == charStack.top())
			{
				temp = 100;
			}
			if ('D' == charStack.top())
			{
				temp = 500;
			}
			if ('M' == charStack.top())
			{
				temp = 1000;
			}
			num += temp;
			charStack.pop();
		}
		return num;
	}

	int romanToInt2(string s)
	{
		int num = 0;
		for (int i = s.size() - 1; i > -1; --i)
		{

			if ('I'==s[i])
			{
				num += 1;
			}
			if ('V' == s[i])
			{
				num += 5;
			}
			if ('X' == s[i])
			{
				num += 10;
			}
			if ('L' == s[i])
			{
				num += 50;
			}
			if ('C' == s[i])
			{
				num += 100;
			}
			if ('D' == s[i])
			{
				num += 500;
			}
			if ('M' == s[i])
			{
				num += 1000;
			}
			if (i > 0)
			{
				if ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I')
				{
					num -= 2;
				}
				if ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X')
				{
					num -= 20;
				}
				if ((s[i] == 'M' || s[i] == 'D') && s[i - 1] == 'C')
				{
					num -= 200;
				}
			}
		}
		return num;
	}
};