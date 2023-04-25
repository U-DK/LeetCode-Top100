#pragma once
#include "No_0_common.h"
#include <unordered_map>

class No_11
{
public:
	int maxArea(vector<int>& height) 
	{
		int low = 0, high = height.size() - 1;
		int ret = 0;
		while (low<high)
		{
			ret = max(ret, min(height[low], height[high]) * (high - low));
			if (height[low] <= height[high])
			{
				++low;
			}
			else
			{
				--high;
			}
		}
		return ret;
	}

};