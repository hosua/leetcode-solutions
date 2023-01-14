#include <bits/stdc++.h>
using namespace std;

// TODO: 95/115 TC

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
	vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		DFS(root, 0, targetSum);
		cout << endl;
		return res;
    }

	void DFS(TreeNode* node, int sum, int targetSum, vector<int> path={}){
		if (!node)
			return;
		int val = node->val;
		sum += val;
		path.push_back(val);
		if (sum == targetSum and !node->left and !node->right){
			res.push_back(path);	
		}

		DFS(node->left, sum, targetSum, path);
		DFS(node->right, sum, targetSum, path);
	}
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), 
			new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1))));
	int targetSum = 22; 
	
	// TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);
	// int targetSum = 1; // []
	auto res = sol.pathSum(root, targetSum);
	// cout << res.size();
	for (auto lst : res){
		for (int ele : lst){
			cout << ele << " ";
		}
		cout << endl;
	}
}
