#pragma once
#include "No_0_common.h"

class No_39
{
public:

	void Recursion(vector<int>& candidates, int target, vector<int> currentVec, int currentSum, int index, vector<vector<int>>& vec)
	{
		if (currentSum>target)
		{
			return;
		}
		if (currentSum==target)
		{
			vec.push_back(currentVec);
			return;
		}
		for (int i = index; i != candidates.size(); ++i)
		{
			currentVec.push_back(candidates[i]);
			currentSum += candidates[i];
			Recursion(candidates, target, currentVec, currentSum, i, vec);
			currentVec.pop_back();
			currentSum -= candidates[i];
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> result;
		vector<int> vec;
		Recursion(candidates, target, vec, 0, 0, result);
		return result;
	}
};