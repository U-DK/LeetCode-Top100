#pragma once
#include "No_0_common.h"
#include <algorithm>

class No_300
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		vector<int> vec(nums.size(), 1);
		for (int i = 0; i != nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j] && vec[i] < vec[j] + 1)
				{
					vec[i] = vec[j] + 1;
				}
			}
		}

		return *max_element(vec.begin(), vec.end());
	}

	int lengthOfLIS2(vector<int>& nums)
	{
		vector<int> vec;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (vec.empty() || vec[vec.size() - 1] < nums[i])
			{
				vec.push_back(nums[i]);
			}
			else
			{
				auto element = lower_bound(vec.begin(), vec.end(), nums[i]);
				*element = nums[i];
			}
		}
		return vec.size();
	}
};