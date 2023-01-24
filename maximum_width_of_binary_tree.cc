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
	int widthOfBinaryTree(TreeNode* root) {
		int max_width = 0;
		function <int(TreeNode*,int,int)> dfs = [&](TreeNode* node, int left, int right){
			if (!node)
				return 0;
			cout << node->val << "->";
			int l = 0, r = 0;
			if (node->left)
				l = dfs(node->left, left+1, right);
			if (node->right)
				r = dfs(node->right, left, right+1);
			return l+r+1;
		};

		int res = dfs(root,0,0);
		cout << "\n";
		return res;
    }

};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(3, new TreeNode(5), nullptr), new TreeNode(2));
	// TreeNode* root = new TreeNode(1, new TreeNode(3, new TreeNode(5, new TreeNode(6), nullptr), nullptr), new TreeNode(2, nullptr, new TreeNode(9, new TreeNode(7), nullptr)));
	int res = sol.widthOfBinaryTree(root);
	cout << res << endl;
}
