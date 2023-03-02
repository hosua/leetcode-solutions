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
	vector<int> vec;
public:
    int maxProduct(TreeNode* root) {
		long long res = 0;
		helper(root);
		for (int num : vec){
			res = max((long long int) num * (vec[0]-num), res);
		}
		return res % ((long long int)pow(10,9)+7);
    }

	int helper(TreeNode* node){
		if (!node)
			return 0;
		int i = vec.size();
		vec.push_back(node->val);
		int left = helper(node->left);
		int right = helper(node->right);
		vec[i] += left+right;
		return vec[i];
	}
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));
	cout << sol.maxProduct(root) << endl;
}
