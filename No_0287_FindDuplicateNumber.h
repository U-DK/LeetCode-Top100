#pragma once
#include "No_0_common.h"

class No_287
{
public:
	int findDuplicate(vector<int>& nums)
	{
		auto small_or_equal = [&](int cur)
		{
			int count = 0;
			for (auto& num : nums)
			{
				if (num <= cur)
					count++;
			}
			return count;
		};

		int low = 1, high = nums.size();
		int duplicate = -1;
		while (low <= high)
		{
			int cur = (low + high) / 2;

			if (small_or_equal(cur) > cur)
			{
				duplicate = cur;
				break;
				high = cur - 1;
			} else
			{
				low = cur + 1;
			}
		}

		return duplicate;
	}
	int findDuplicate2(vector<int>& nums)
	{
		int slow = nums[0];
		int fast = nums[0];
		do 
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow!=fast);

		slow = nums[0];
		while (slow!=fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return fast;
	}
	int findDuplicate3(vector<int>& nums)
	{
		while (nums[0]!=nums[nums[0]])
		{
			swap(nums[0], nums[nums[0]]);
		}
		return nums[0];
	}
};