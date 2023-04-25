#pragma once
#include "No_0_common.h"
#include <algorithm>

class No_15
{
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		if (nums.size() < 3)
		{
			return {};
		}
		vector<vector<int>> vec;

		if (nums.size() == 3 && nums[0] + nums[1] + nums[2] == 0)
		{
			vec.push_back(nums);
			return vec;
		}
		sort(nums.begin(), nums.end());

		int fixedNum = nums[0];
		if (fixedNum > 0)
		{
			return {};
		}
		int low = 0, high = nums.size()-1;
		int temp = 0;
		for (int i = 0; i != nums.size(); ++i)
		{

			fixedNum = nums[i];
			if (fixedNum>0)
			{
				break;
			}
			if (i > 0 && nums[i - 1] == nums[i])
			{
				continue;
			}
			low = i + 1;
			high = nums.size() - 1;
			while (low<high)
			{
				temp = fixedNum + nums[low] + nums[high];
				if (temp > 0)
				{
					--high;
					continue;
				}
				if (temp < 0)
				{
					++low;
					continue;
				}
				if (temp == 0)
				{
					vec.push_back({ fixedNum,nums[low],nums[high] });
					++low;
					while (low < high && nums[low] == nums[low - 1])
					{
						++low;
					}
					--high;
					while (low<high&&nums[high]==nums[high+1])
					{
						--high;
					}
				}
			}

		}

		return vec;
		
	}
};