#pragma once
#include "No_0_common.h"
#include <algorithm>

class No_240
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		for (auto& a:matrix)
		{
			if (binary_search(a.begin(), a.end(), target))
			{
				return true;
			}
		}
		return false;
	}

	bool searchMatrix2(vector<vector<int>>& matrix, int target)
	{
		int i = 0;
		int n = matrix.size();
		int m = matrix[0].size();
		int j = m - 1;

		while (i < n && j >= 0)
		{
			int temp = matrix[i][j];
			if (temp == target)
			{
				return true;
			}
			if (temp > target)
			{
				--j;
			}
			else
			{
				++i;
			}
			
		}
		return false;
	}
};