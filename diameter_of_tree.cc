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

// 100/104 TC
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
		if (!root->left && !root->right)
			return 0;

		int left = 0, right = 0;
		if (root->left)
			DFS(root->left, left);
		if (root->right)
			DFS(root->right, right);
		return left+right;
    }

	void DFS(TreeNode* root, int& max_depth, int depth=0){
		if (!root)
			return;
		depth++;
		if (depth > max_depth)
			max_depth = depth;
		if (root->left){
			DFS(root->left, max_depth, depth);
		}
		if (root->right){
			DFS(root->right, max_depth, depth);
		}
	}
};

int main(){
	// TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
	TreeNode* root = new TreeNode(3, new TreeNode(1), new TreeNode(2));
	Solution sol;
	cout << sol.diameterOfBinaryTree(root);
}
