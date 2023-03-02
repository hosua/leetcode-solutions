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
	int kthSmallest(TreeNode* root, int k) {
		int ki = 0;
		function <void(TreeNode*)> dfs = [&](TreeNode* node){
			if (not node)
				return;

			if (node->left)
				dfs(node->left);
			
			ki++;
			if (ki == k){
				res = node->val;
				return;
			}

			if (node->right)
				dfs(node->right);
		};

		dfs(root);
		return res;
    }
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
	int k = 1; // 3
	// TreeNode* root = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), nullptr), new TreeNode(6));
	// int k = 2; // 2
	int res  = sol.kthSmallest(root, k);
	cout << res << endl;
}
