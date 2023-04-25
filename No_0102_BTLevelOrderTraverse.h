#pragma once
#include "No_0_common.h"
#include <queue>

class No_102
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		if (!root)
		{
			return {};
		}
		vector<vector<int>> vec;
		vector<int> value;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int length = q.size();
			for (int i = 0; i != length; ++i)
			{
				auto node = q.front();
				q.pop();
				value.push_back(node->val);
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
			}
			vec.push_back(value);
			value.clear();
		}
		return vec;
	}
};