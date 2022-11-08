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
    int maxDepth(TreeNode* root) {
		if (!root) return 0;
		int max_depth = 0;
		DFS(root, max_depth);
		return max_depth;
    }
	void DFS(TreeNode* root, int &max_depth, int depth=1){
		if (!root)
			return;
		if (root->left)
			DFS(root->left, max_depth, depth+1);
		if (root->right)
			DFS(root->right, max_depth, depth+1);
		if (depth > max_depth) max_depth = depth;
	}
};
