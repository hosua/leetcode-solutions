#include <bits/stdc++.h>
using namespace std;

// TODO: Revisit this

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
    bool isValidBST(TreeNode* root) {
		return isValidBSTUtil(root);
    }
	
private:
	bool isValidBSTUtil(TreeNode* root, long int m=LONG_MIN, long int M=LONG_MAX){
		if (!root)
			return true;
		if (root->val > m && root->val < M)
			return isValidBSTUtil(root->left, m, root->val) && isValidBSTUtil(root->right, root->val, M);
		return false;
	}
};

void tests(){
    Solution sol;
	TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3)); // 1
	TreeNode* root2 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6))); // 0
	TreeNode* root3 = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7))); // 0
	vector<TreeNode*> roots = {root1, root2, root3};
	for (TreeNode* root : roots){
		bool res = sol.isValidBST(root);
		cout << res << "\n";
	}
}


int main(){
	tests();
}
