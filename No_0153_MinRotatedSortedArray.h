#pragma once
#include "No_0_common.h"

class No_153
{
public:
	int findMin(vector<int>& nums)
	{
		if (nums[0] <= nums[nums.size() - 1])
		{
			return nums[0];
		}
		int min = INT_MAX;
		int length= nums.size();
		int left = 0;
		int right = length-1;
		while (left<right)
		{
			if (nums[left] < min)
			{
				min = nums[left];
			}
			int mid = left + (right - left) / 2;
			if (nums[left] <= nums[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		if (nums[left] < min)
		{
			min = nums[left];
		}
		return min;
	}

	int findMin2(vector<int>& nums)
	{
		int length = nums.size();
		int left = 0, right = length - 1;
		while (left<right)
		{
			int mid = left + (right - left) / 2;
			if (nums[right] < nums[mid])
			{
				left = mid + 1;
			}
			if (nums[right] >= nums[mid])
			{
				right = mid;
			}
		}
		return nums[right];
	}
};