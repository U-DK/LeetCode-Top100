#pragma once
#include "No_0_common.h"
#include <algorithm>

class No_33
{
public:
	int search(vector<int>& nums, int target)
	{
		if (target<nums[0] && target>nums[nums.size() - 1])
		{
			return -1;
		}
		int temp = 0;
		int index = 0;
		if (target >= nums[0])
		{
			temp = nums[0];
			index = 0;
			while (index + 1 < nums.size() && temp <= nums[index + 1])
			{
				if (target == nums[index])
				{
					return index;
				}
				++index;
			}

		}
		else
		{
			temp = nums[nums.size() - 1];
			index = nums.size() - 1;
			while (index - 1 >= 0 && temp >= nums[index - 1])
			{
				if (target == nums[index])
				{
					return index;
				}
				--index;
			}
		}
		if (target == nums[index])
		{
			return index;
		}
		return -1;
	}

	int search2(vector<int>& nums, int target)
	{
		int length = nums.size();
		int left = 0, right = length - 1;
		while (left<=right)
		{
			int mid = left + (right - left) / 2;
			if (target == nums[mid])
			{
				return mid;
			}
			if (nums[left] <= nums[mid])
			{
				if (nums[left] <= target && target < nums[mid])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				if (nums[mid] < target && target <= nums[right])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};