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
	int count;
public:
	Solution(){
		count = 0;
	}
    int countNodes(TreeNode* root) {
       	helper(root); 
		return count;
    }

	void helper(TreeNode* root){
		count++;
		if (root->left){
			helper(root->left);
		}
		if (root->right){
			helper(root->right);
		}
	}
};

int main(){
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));
	Solution sol;
	cout << sol.countNodes(root);
}
