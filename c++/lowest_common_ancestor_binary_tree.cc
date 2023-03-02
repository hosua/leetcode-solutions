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
	TreeNode* res;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		function <bool(TreeNode*)> dfs = [&](TreeNode* node){
			if (!node)
				return false;
			bool mid = (node->val == p->val or node->val == q->val);
			bool left = dfs(node->left);
			bool right = dfs(node->right);
			if (left + mid + right >= 2)
				res = node;
			return left or mid or right;
		};
		res = nullptr;
		dfs(root);
		return res;
    }
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))), new TreeNode(1, new TreeNode(0), new TreeNode(8)));
	TreeNode *p = new TreeNode(5), *q = new TreeNode(1);
	TreeNode* res = sol.lowestCommonAncestor(root, p, q);
	cout << "\n";
	cout << res->val << endl;
}
