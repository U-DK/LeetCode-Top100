#pragma once
#include "No_0_common.h"
#include <unordered_map>

class No_105
{
public:
	void Build(vector<int> preorder, vector<int> inorder, bool isLeft, TreeNode* node)
	{
		if (preorder.size()<=0)
		{
			return;
		}
		TreeNode* root = new TreeNode(preorder[0]);
		if (isLeft)
		{
			node->left = root;
		} else
		{
			node->right = root;
		}
		if (preorder.size() == 1)
		{
			return;
		}
		vector<int> halfInorder;
		vector<int> halfPreorder;
		int index = 0;
		for (int i = 0; i != inorder.size(); ++i)
		{
			if (inorder[i] == root->val)
			{
				index = i;
				break;
			}
			halfInorder.push_back(inorder[i]);
		}
		for (int i = 1; i != halfInorder.size()+1; ++i)
		{
			halfPreorder.push_back(preorder[i]);
		}
		Build(halfPreorder, halfInorder, true, root);

		halfInorder.clear();
		halfPreorder.clear();
		for (int i = index + 1; i != inorder.size(); ++i)
		{
			halfInorder.push_back(inorder[i]);
		}

		for (int i = preorder.size() - 1; i > preorder.size() - halfInorder.size() - 1; --i)
		{
			halfPreorder.push_back(preorder[i]);
		}
		reverse(halfPreorder.begin(), halfPreorder.end());
		Build(halfPreorder, halfInorder, false, root);

	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		TreeNode* root = new TreeNode(preorder[0]);
		if (preorder.size()==1)
		{
			return root;
		}
		if (preorder.size()==2)
		{
			if (preorder[0] == inorder[0])
			{
				root->right = new TreeNode(preorder[1]);
			}
			else
			{
				root->left = new TreeNode(preorder[1]);
			}
			return root;
		}

		TreeNode* dummy = new TreeNode();
		Build(preorder, inorder, true, dummy);

		return dummy->left;
	}


	TreeNode* Build2(int& rootIndex, vector<int>& preorder, unordered_map<int, int>& map,int left,int right)
	{
		if (left>right)
		{
			return NULL;
		}

		int rootValue = preorder[rootIndex++];
		TreeNode* root = new TreeNode(rootValue);
		root->left = Build2(rootIndex, preorder, map, left, map[rootValue] - 1);
		root->right = Build2(rootIndex, preorder, map, map[rootValue] + 1, right);
		return root;
	}
	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder)
	{
		int rootIndex = 0;
		unordered_map<int, int> map;
		for (int i = 0; i != inorder.size(); ++i)
		{
			map[inorder[i]] = i;
		}
		return Build2(rootIndex, preorder, map, 0, inorder.size() - 1);
	}
};