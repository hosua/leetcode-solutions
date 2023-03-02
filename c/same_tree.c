#include <stdbool.h>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == q)	// both must be NULL since tree should be acyclic
		return true;
	else if (!p || !q) // one NULL but not the other, mismatch.
		return false;
	else if (p->val != q->val) // values are not equal so we again have a mismatch
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
