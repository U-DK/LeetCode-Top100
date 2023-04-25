#pragma once
#include "No_0_common.h"

class No_104
{
public:
	int Recursion(TreeNode* node)
	{
		if (!node)
		{
			return 0;
		}
		int left = Recursion(node->left);
		int right = Recursion(node->right);
		return max(left, right) + 1;
	}
	int maxDepth(TreeNode* root)
	{
		int result = Recursion(root);
		return result;
	}
};