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
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return helper(nums, 0, nums.size()-1);     
		}

		TreeNode* helper(vector<int> nums, int left, int right){
			if (left > right)
				return nullptr;
			int mid = (left+right)/2;
			TreeNode* root = new TreeNode(nums[mid]);
			root->left = helper(nums, left, mid-1);
			root->right = helper(nums, mid+1, right);
			return root;
		}
};

void printTree(TreeNode* root){
	if (!root) return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}
int main(){
	Solution sol;
	// vector<int> nums = {-10,-3,0,5,9};
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	TreeNode* res = sol.sortedArrayToBST(nums);
	printTree(res);
}
