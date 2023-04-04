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
    	if (!root->left && !root->right)
			return true;
		return isSymmetric(root->left, root->right);
    }

private:
	bool isSymmetric(TreeNode* l, TreeNode* r){
		if (!l|| !r)
			return !l && !r;
		if (l->val != r->val)
			return false;
		return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
	}
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3))); // True
	bool res = sol.isSymmetric(root);
	cout << res << "\n";
}
