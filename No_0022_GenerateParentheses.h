#pragma once
#include "No_0_common.h"

class No_22
{
public:
	vector<string> vec;
	void Recursion(int left, int right, string s)
	{
		if (left < 0 || right < 0)
		{
			return;
		}
		if (left == 0 && right == 0)
		{
			vec.push_back(s);
		}
		Recursion(left - 1, right, s + "(");
		if (left < right)
		{
			Recursion(left, right - 1, s + ")");
		}
	}
	vector<string> generateParenthesis(int n)
	{
		Recursion(n, n, "");
		return vec;
	}

	void Recursion2(vector<string>& vec, string& s, int left, int right, int max)
	{
		if (s.size() >= 2 * max)
		{
			vec.push_back(s);
			return;
		}
		if (left < max)
		{
			s.push_back('(');
			Recursion2(vec, s, left + 1, right, max);
			s.pop_back();
		}
		if (right < left)
		{
			s.push_back(')');
			Recursion2(vec, s, left, right + 1, max);
			s.pop_back();
		}
	}
};