#pragma once
#include "No_0_common.h"

class No_101
{
public:
	bool Recursion(TreeNode* left, TreeNode* right)
	{
		if (NULL == left && NULL == right)
		{
			return true;
		}
		if (NULL == left || NULL == right)
		{
			return false;
		}
		if (left->val != right->val)
		{
			return false;
		}
		return Recursion(left->left, right->right) && Recursion(left->right, right->left);

	}
	bool isSymmetric(TreeNode* root)
	{
		return Recursion(root->left, root->right);
	}
};