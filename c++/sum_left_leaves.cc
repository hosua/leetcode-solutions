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
	int sumOfLeftLeaves(TreeNode* root) {
		int res = 0;
   		function <void(TreeNode*,string)> dfs = [&](TreeNode* node,string id){
			if (not node)
				return;
			if (node->left)
				dfs(node->left, "left");
			if (node->right)
				dfs(node->right, "right");

			if (id == "left" and not node->left and not node->right)
				res += node->val;	
		};

		dfs(root,"root");
		return res;
    }
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	int res = sol.sumOfLeftLeaves(root);
	cout << res << "\n";
}
