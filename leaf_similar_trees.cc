#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      	vector<int> l1;
		vector<int> l2;
		
		DFS(root1, l1);
		DFS(root2, l2);
		return l1 == l2;
    }

	void DFS(TreeNode* node, vector<int>& lst){
		if (!node)
			return;
		if (isLeaf(node))
			lst.push_back(node->val);
		DFS(node->left, lst);
		DFS(node->right, lst);
	}

	bool isLeaf(TreeNode* node){
		return (!node->left and !node->right);
	}
};
