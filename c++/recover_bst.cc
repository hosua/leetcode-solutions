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
private:
public:
	void recoverTree(TreeNode* root) {
		if (!root)
			return;
   		if (root->left){
			if (root->left->val < root->val)
				recoverTree(root->left);
			else
				swap(root->left->val, root->val);
		}     
		if (root->right){
			if (root->right->val > root->val)
				recoverTree(root->right);
			else
				swap(root->right->val, root->val);
		}
    }
};

void levelOrder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()){
		TreeNode* node = q.front(); q.pop();
		if (node){
			cout << node->val << "->";
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
	cout << "\n";
}

int main(){
    Solution sol;
	// TreeNode* root = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr); // 3 1 2
	TreeNode* root = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), nullptr));
	levelOrder(root);
	sol.recoverTree(root);
	levelOrder(root);
}
