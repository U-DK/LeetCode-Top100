#pragma once
#include "No_0_common.h"

class No_543
{
public:

	int Recursion(TreeNode* node, int& result)
	{
		if (!node)
		{
			return 0;
		}
		int left = Recursion(node->left, result);
		int right = Recursion(node->right, result);
		result = max(left + right, result);
		return max(left, right) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root)
	{
		int result = 0;
		Recursion(root, result);
		return result;
	}
};