#pragma once
#include "No_0_common.h"

class No_35
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int length = nums.size();
		int left = 0, right = length - 1;
		int mid = -1;
		int result = -1;

		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (target <= nums[mid])
			{
				result = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}

		}
		if (result != -1)
		{
			return result;
		}

		left = 0; right = length - 1;
		while (left<=right)
		{
			mid = left + (right - left) / 2;
			if (target >= nums[mid])
			{
				result = mid;
				left = mid + 1;
			} else
			{
				right = mid - 1;
			}
		}

		return result+1;

	}

	int searchInsert2(vector<int>& nums, int target)
	{
		int length = nums.size();
		int left = 0, right= length - 1;
		if (target<nums[left])
		{
			return left;
		}
		if (target > nums[right])
		{
			return length;
		}

		while (left<right)
		{
			int mid = left + (right - left) / 2;
			if (target > nums[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return left;
	}
};