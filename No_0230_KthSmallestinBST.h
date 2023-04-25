#pragma once
#include "No_0_common.h"
#include <algorithm>
#include <stack>

class No_230
{
public:
	int kthSmallest(TreeNode* root, int k)
	{
		vector<int> vec(k, INT_MAX);
		make_heap(vec.begin(), vec.end());
		TreeNode* temp = root;
		stack<TreeNode*> valueStack;
		valueStack.push(root);
		while (!valueStack.empty())
		{
			if (vec[0] != INT_MAX && valueStack.size() == 1)
			{
				break;
			}
			temp = valueStack.top();
			valueStack.pop();
			if (!temp)
			{
				continue;
			}
			if (temp->val <= vec[0])
			{
				vec[0] = temp->val;
				make_heap(vec.begin(), vec.end());
			}
			valueStack.push(temp->right);
			valueStack.push(temp->left);
		}
		return vec[0];
	}


	void Recursion(TreeNode* node, int k, int& count, int& result)
	{
		if (!node)
		{
			return;
		}
		Recursion(node->left, k, count, result);
		++count;
		if (k==count)
		{
			result = node->val;
			return;
		}
		if (count > k)
		{
			return;
		}
		Recursion(node->right, k, count, result);
	}
	int kthSmallest2(TreeNode* root, int k)
	{
		int count = 0;
		int result = -1;
		Recursion(root, k, count, result);
		return result;
	}
};