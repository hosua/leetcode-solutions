#include <bits/stdc++.h>
using namespace std;
// Binary search tree to greater sum tree

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
	Solution(): _running_sum(0){}

    TreeNode* bstToGst(TreeNode* root) {
		function<void(TreeNode*)> dfs;
		dfs = [&](TreeNode* node){
			if (!node)
				return;
			if (node->right)
				dfs(node->right);
			_running_sum += node->val;
			node->val = _running_sum;
			if (node->left)
				dfs(node->left);
		};
   		dfs(root);
		return root;
    }
private:
	int _running_sum;
};

void print(TreeNode* node){
	if (!node)
		return;
	print(node->left);
	cout << node->val << "->";
	print(node->right);
}

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))), new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));
	TreeNode* res = sol.bstToGst(root);
	print(res);
	cout << "\n";
}
