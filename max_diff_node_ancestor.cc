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
	int max_diff;
public:
	Solution(): max_diff(INT_MIN){}
    int maxAncestorDiff(TreeNode* root) {
       	helper(root, root->val, root->val); 
		return max_diff;
    }

	void helper(TreeNode* node, int m, int M){
		int diff = M - m;
		if (diff > max_diff)
			max_diff = diff;
		if (!node)
			return;
		m = min(node->val, m);
		M = max(node->val, M);
		helper(node->left, m, M);
		helper(node->right, m, M);
	}
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(8, new TreeNode(3, new TreeNode(1), new TreeNode(6, new TreeNode(4), new TreeNode(7))), new TreeNode(10, nullptr, new TreeNode(14, new TreeNode(13), nullptr)));
	cout << sol.maxAncestorDiff(root) << endl; 
}
