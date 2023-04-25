#pragma once
#include "No_0_common.h"

class No_31
{
public:
	void nextPermutation(vector<int>& nums)
	{
		if (nums.size() <= 1)
		{
			return;
		}
		auto first = nums.begin();
		auto last = nums.end();

		auto i = last;
		--i;
		auto ii = i;
		auto j = last;
		while (true)
		{
			ii = i;
			--i;
			if (*i < *ii)
			{
				j = last;
				while (!(*--j > *i));
				iter_swap(i, j);
				reverse(ii, last);
				return;
			}
			if (i == first)
			{
				reverse(first, last);
				return;
			}
		}
	}
};