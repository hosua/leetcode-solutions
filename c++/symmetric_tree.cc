// https://leetcode.com/problems/symmetric-tree/

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
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return isSymmetric(root->left, root->right);
    }

	bool isSymmetric(TreeNode* left, TreeNode* right){
		// How the fuck does this work?
		if (!left || !right)
			return !left && !right;
		if (left->val != right->val)
			return false;

		return isSymmetric(left->left, right->right) && isSymmetric(right->left, left->right);
    }
};

int main(){
	Solution sol;
	TreeNode pll = TreeNode(3);
	TreeNode plr = TreeNode(4);
	TreeNode prl = TreeNode(4);
	TreeNode prr = TreeNode(3);
	TreeNode pl = TreeNode(2, &pll, &plr);
	TreeNode pr = TreeNode(2, &prl, &prr);
	TreeNode p = TreeNode(1, &pl, &pr);
	bool res = sol.isSymmetric(&p);
	cout << res << endl;
}
