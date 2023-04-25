#pragma once
#include "No_0_common.h"
#include <unordered_map>

class No_1
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> vecMap;
		for (int i=0;i!=nums.size();++i)
		{
			if (vecMap.count(target-nums[i])>0)
			{
				return { vecMap[nums[i]],i };
			}
			vecMap[nums[i]] = i;
		}
		return { -1,-1 };
	}
};
