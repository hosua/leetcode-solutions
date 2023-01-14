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
	map<int, int> sum_freqs; // sum, freq
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
    	dfs(root);
		for (auto [sum, freq] : sum_freqs)
			cout << sum << " " << freq << endl;
		return {};
    }
	int dfs(TreeNode* node){
		if (!node)
			return 0;
		int val = node->val;
		cout << val << endl;
		int left = dfs(node->left);
		int right = dfs(node->right);
		return left+right;
	}
};
int main(){
	Solution sol;
	TreeNode* root = new TreeNode(5, new TreeNode(2), new TreeNode(-3));
	vector<int> res = sol.findFrequentTreeSum(root);
	for (int num : res)
		cout << num << " ";
	cout << endl;

}
