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
	int res;
public:
	int goodNodes(TreeNode* root) {
       	res = 0; 

		function<void(TreeNode*,int)> dfs = [&](TreeNode* node, int curr_min){
			if (!node)
				return;
			if (node->val >= curr_min){
				res++;
				curr_min = node->val;
			}
			dfs(node->left, curr_min);
			dfs(node->right, curr_min);
		};

		dfs(root, root->val);
		return res; 
    }
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(3, new TreeNode(1, new TreeNode(3), nullptr), new TreeNode(4, new TreeNode(1), new TreeNode(5)));
	// 4
	// TreeNode* root = new TreeNode(3, new TreeNode(3, new TreeNode(4), new TreeNode(2)), nullptr); // 3
	// TreeNode* root = new TreeNode(1); // 1
	int res = sol.goodNodes(root);
	cout << res << endl;
}
