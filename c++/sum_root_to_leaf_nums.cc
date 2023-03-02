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
	int sum;
public:
    int sumNumbers(TreeNode* root) {
		sum = 0;
		dfs(root);
       	return sum; 
    }
	void dfs(TreeNode* node, string path_str=""){
		if (!node)
			return;
		int val = node->val;
		char ch = *to_string(val).c_str();
		path_str += ch;
		if (!node->left and !node->right)
			sum += stoi(path_str);
		dfs(node->left, path_str);
		dfs(node->right, path_str);
	}
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	int res = sol.sumNumbers(root);
	cout << res << endl;
}
