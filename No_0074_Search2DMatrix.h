#pragma once
#include "No_0_common.h"
#include <algorithm>

class No_74
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		for (auto& a : matrix)
		{
			if (a[0] > target)
			{
				return false;
			}
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
		while (i>=0&&i<n&&j>=0&&j<m)
		{
			int temp = matrix[i][j];
			if (target > temp)
			{
				++i;
			}
			else if (target < temp)
			{
				--j;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};