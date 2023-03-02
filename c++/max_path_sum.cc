#include <bits/stdc++.h>
using namespace std;

// TODO
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
	int max_sum;
public:
	Solution():max_sum(INT_MIN){}
    int maxPathSum(TreeNode* root) {
		traverse(root);
		return max_sum;
    }

	int traverse(TreeNode* node, int sum=0){
		if (!node)
			return 0;
		int left = traverse(node->left, node->val+sum);
		int right = traverse(node->right, node->val+sum);
		int path_sum = max(node->val+max(left, right), node->val);
		if (max_sum < path_sum && max_sum < node->val+left+right)
			max_sum = max(path_sum, node->val+left+right);
		return path_sum;
	}
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	// TreeNode* root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	cout << sol.maxPathSum(root) << endl;
}
