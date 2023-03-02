#include <bits/stdc++.h>

using namespace std;
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
		vector<int> inorderTraversal(TreeNode* root) {
			if (!root) return {};
			vector<int> res;
			DFS(root, res);
			return res;
		}
		
		void DFS(TreeNode* root, vector<int> &v){
			if (!root) return;
			if (root->left) DFS(root->left, v);
			v.push_back(root->val);
			if (root->right) DFS(root->right, v);
		}
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
	vector<int> res = sol.inorderTraversal(root);
	for (int num : res)
		cout << num << endl;
}
