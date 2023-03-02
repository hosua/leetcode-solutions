// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void swap(struct TreeNode** a, struct TreeNode** b){
	struct TreeNode* temp = *a;
	*a = *b;
	*b = temp;
}

struct TreeNode* invertTree(struct TreeNode* root){
	if (!root)
		return root;
	swap(&root->left, &root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}
