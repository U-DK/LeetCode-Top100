#pragma once
#include "No_0_common.h"
#include <stack>

class No_94
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		if (NULL==root)
		{
			return {};
		}
		vector<int> vec;
		stack<TreeNode*> nodeStack;
		while (NULL != root || !nodeStack.empty())
		{
			while (NULL!=root)
			{
				nodeStack.push(root);
				root = root->left;
			}
			root = nodeStack.top();
			nodeStack.pop();
			vec.push_back(root->val);
			root = root->right;
		}
		return vec;

	}

	vector<int> inorderTraversal2(TreeNode* root)
	{
		if (NULL==root)
		{
			return {};
		}
		vector<int> vec;
		TreeNode* temp = NULL;
		while (NULL!=root)
		{
			if (NULL!=root->left)
			{
				temp = root->left;
				while (NULL!=temp->right)
				{
					temp = temp->right;
				}
				temp->right = root;
				temp = root->left;
				root->left = NULL;
				root = temp;
			}
			else
			{
				vec.push_back(root->val);
				root = root->right;
			}
		}
		return vec;
	}
};