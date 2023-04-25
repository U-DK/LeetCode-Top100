#pragma once
#include "No_0_common.h"
#include <queue>

class No_199
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		if (!root)
		{
			return {};
		}
		vector<int> vec;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int length = q.size();
			for (int i = 0; i != length; ++i)
			{
				auto node = q.front();
				q.pop();
				if (0 == i)
				{
					vec.push_back(node->val);
				}
				if (node->right)
				{
					q.push(node->right);
				}
				if (node->left)
				{
					q.push(node->left);
				}
			}
		}
		return vec;
	}

	void Recursion(TreeNode* node, int level, vector<int>& vec)
	{
		if (!node)
		{
			return;
		}
		if (vec.size() < level + 1)
		{
			vec.push_back(node->val);
		}
		Recursion(node->right, level + 1, vec);
		Recursion(node->left, level + 1, vec);

	}
	vector<int> rightSideView2(TreeNode* root)
	{
		vector<int> vec;
		Recursion(root, 0, vec);
	}
};