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
    int diameterOfBinaryTree(TreeNode* root) {
		if (!root->left && !root->right)
			return 0;
       	// BFS
		queue<TreeNode*> q;
		q.push(root);
		int max_w = 0;
		while (!q.empty()){
			int width = q.size();
			if (width > max_w) 
				max_w = width;
			TreeNode* node = q.front();
			q.pop();
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		return max_w;
    }
};

int main(){
	TreeNode* root = new TreeNode(2, new TreeNode(3, new TreeNode(1), nullptr), nullptr);
	Solution sol;
	cout << sol.diameterOfBinaryTree(root);
}
