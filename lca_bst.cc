#include <stdio.h>

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val && root->val > q->val)
			root = lowestCommonAncestor(root->left, p, q);
		if (root->val < p->val && root->val < q->val)
			root = lowestCommonAncestor(root->right, p, q);

		return root;
    }
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);

	printf("%i\n", sol.lowestCommonAncestor(root, root->left, root->left->right)->val);

}
