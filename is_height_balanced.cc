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
	bool is_balanced;
public:
	Solution():is_balanced(true){}
    bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		helper(root);
		return is_balanced;
    }
	int helper(TreeNode* node){
		if (!node or !is_balanced)
			return 0;
		int left = helper(node->left);
		int right = helper(node->right);
		// printf("left: %i\tright: %i\n", left, right);
		if (abs(left-right) > 1){
			is_balanced = false;
			return 0;
		}
		return 1+max(left,right);
	}
};


int main(){
	Solution sol;
	// TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))); // T
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3)), new TreeNode(2)); // F
	// TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), new TreeNode(2, new TreeNode(3), new TreeNode(4, new TreeNode(4), nullptr))); // F
	cout << sol.isBalanced(root) << endl;
}
