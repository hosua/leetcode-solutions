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
public:
    int averageOfSubtree(TreeNode* root) {
		int res = 0;
		function <pair<int,int>(TreeNode*)> dfs;
		dfs = [&](TreeNode* node) -> pair<int,int> {
			if (!node)
				return make_pair(0,0);
			auto [left, n] = dfs(node->left);
			auto [right, m] = dfs(node->right);
			int sum = left+right+node->val;
			int avg = sum / (n+m+1);
			// cout << "val: " << node->val << "\tavg: " << sum << "/(" << n << "+" << m << "+1)=" << avg << "\n";
			if (node->val == avg)
				res++;
			return make_pair(sum,(n+m)+1);
		};
		dfs(root);
		return res;
    }
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(4, new TreeNode(8, new TreeNode(0), new TreeNode(1)), new TreeNode(5, nullptr, new TreeNode(6)));
	int res = sol.averageOfSubtree(root);
	cout << res << "\n";
}
