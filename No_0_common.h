#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr)
	{
	}
	ListNode(int x) : val(x), next(nullptr)
	{
	}
	ListNode(int x, ListNode* next) : val(x), next(next)
	{
	}
};


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

  static void CommonBuildTree(TreeNode* node, int value)
  {
	  while (node)
	  {
		  if (node->val < value)
		  {
			  if (!node->right)
			  {
				  node->right = new TreeNode(value);
				  return;
			  }
			  else
			  {
				  node = node->right;
			  }
		  }
		  if (node->val > value)
		  {
			  if (!node->left)
			  {
				  node->left = new TreeNode(value);
				  return;
			  }
			  else
			  {
				  node = node->left;
			  }
			  
		  }
	  }

  }