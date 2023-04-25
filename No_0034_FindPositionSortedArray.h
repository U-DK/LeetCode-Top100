#pragma once
#include "No_0_common.h"

class No_34
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int length = nums.size();

		int left = 0, right = length - 1;

		int mid = -1;
		while (left<=right)
		{
			mid = left + (right - left) / 2;
			if (target == nums[mid])
			{
				break;
			}
			if (target < nums[mid])
			{
				right = mid - 1;
				mid = -1;
				continue;
			}
			left = mid + 1;
			mid = -1;
		}
		if (-1 == mid)
		{
			return { -1,-1 };
		}
		int l = mid-1, r = mid+1;
		while (l >= 0 || r < length)
		{

			if (l < 0 && nums[r] != target)
			{
				break;
			}
			if (r >= length && nums[l] != target)
			{
				break;
			}
			if (l >= 0 && r < length && nums[l] != target && nums[r] != target)
			{
				break;
			}
			if (l >= 0 && nums[l] == target)
			{
				--l;
			}
			if (r<length&&nums[r] == target)
			{
				++r;
			}
		}
		return { l + 1,r - 1 };
	}
};