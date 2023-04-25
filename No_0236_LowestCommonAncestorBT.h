#pragma once
#include "No_0_common.h"

class No_236
{
public:
	void FindPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& stop)
	{
		if (!root||stop)
		{
			return;
		}
		if (root->val == target->val)
		{
			stop = true;
			path.push_back(root);
			return;
		}
		FindPath(root->left, target, path, stop);
		if (stop)
		{
			path.push_back(root);
			return;
		}
		FindPath(root->right, target, path, stop);
		if (stop)
		{
			path.push_back(root);
			return;
		}

	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		vector<TreeNode*> pathP;
		vector<TreeNode*> pathQ;
		bool stop = false;
		FindPath(root, p, pathP, stop);
		stop = false;
		FindPath(root, q, pathQ, stop);
		int startP = 0;
		int startQ = 0;
		if (pathP.size() > pathQ.size())
		{
			startP += (pathP.size() - pathQ.size());
		}
		else
		{
			startQ += (pathQ.size() - pathP.size());
		}
		while (pathP[startP]!=pathQ[startQ])
		{
			++startQ;
			++startP;
		}
		return pathP[startP];
	}

	TreeNode* result = NULL;
	bool Recursion(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root)
		{
			return false;
		}
		if (result)
		{
			return false;
		}
		int count = 0;
		if (root->val == p->val || root->val == q->val)
		{
			++count;
		}
		if (Recursion(root->left, p, q))
		{
			++count;
		}
		if (Recursion(root->right, p, q))
		{
			++count;
		}
		if (count >= 2)
		{
			result = root;
		}
		return count > 0;
	}
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		Recursion(root, p, q);
		return result;
	}
};