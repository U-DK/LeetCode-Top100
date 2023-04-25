#pragma once
#include "No_0_common.h"

class No_98
{
public:
	TreeNode* prev = NULL;
	bool Validation(TreeNode* node)
	{
		if (NULL==node)
		{
			return true;
		}
		if (!Validation(node->left))
		{
			return false;
		}
		if (prev != NULL && prev->val >= node->val)
		{
			return false;
		}
		prev = node;
		return Validation(node->right);
	}
	bool isValidBST(TreeNode* root)
	{
		return Validation(root);
	}
};