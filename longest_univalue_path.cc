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
	int longest_path;
public:
	int longestUnivaluePath(TreeNode* root) {
       	longest_path = 0; 

		if (!root or (!root->left and !root->right))
			return 0;
		dfs(root);
		return longest_path;
    }
	
	int dfs(TreeNode* node){
		if (!node)
			return 0;
		int left = dfs(node->left), right = dfs(node->right);
		// cout << node->val << endl;
		// if node exists and values match, increment distance, otherwise, reset it to 0
		(node->left and node->left->val == node->val) ? left += 1 : left = 0;
		(node->right and node->right->val == node->val) ? right += 1 : right = 0;
		int longest_child =	left+right;
		longest_path = max(longest_path, longest_child);

		return max(left,right);
	}
};

int main(){
	Solution sol;
	// TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(1), new TreeNode(1)), new TreeNode(5, nullptr, new TreeNode(5))); // 2
	TreeNode* root = new TreeNode(1, new TreeNode(4, new TreeNode(4), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(5))); // 2
	// TreeNode* root = new TreeNode(1); // 0
	// TreeNode* root = new TreeNode(1, new TreeNode(1), nullptr); // 1
	int res = sol.longestUnivaluePath(root);
	cout << res << endl;
}
