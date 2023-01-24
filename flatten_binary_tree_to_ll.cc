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

void printInorder(TreeNode* node){
	if (!node)	
		return;

	printInorder(node->left);
	cout << node->val << "->";
	printInorder(node->right);
}

class Solution {
private:
	void dfs(TreeNode* node, vector<int>& path){
		if (!node)
			return;
		
		path.push_back(node->val);
		dfs(node->left, path);
		dfs(node->right, path);
	}
public:
	void flatten(TreeNode* root) {
		vector<int> path;
		dfs(root, path);

		root = new TreeNode(root->val);
		for (int i = 1; i < path.size(); i++){
			int node = path[i];
			root->right = new TreeNode(node);
			root = root->right;
		}
		printInorder(root);
    }

};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));
	printInorder(root);
	cout << endl;

	sol.flatten(root);

	printInorder(root);
	cout << endl;
}
