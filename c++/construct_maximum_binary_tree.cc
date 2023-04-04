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

// TODO: I don't get it.
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		const int N = nums.size();

		function <TreeNode*(int,int)> helper;
		helper = [&](int l, int r) -> TreeNode* {
			if (l > r)
				return nullptr;
			else if (l == r)
				return new TreeNode(nums[l]);
			
			int max_idx = -1, max_val = -1;
			for (int i = l; i <= r; i++){
				if (nums[i] > max_val){
					max_val = nums[i];
					max_idx = i;
				}
			}
			
			TreeNode* root = new TreeNode(max_val);
			root->left = helper(l, max_idx-1);
			root->right = helper(max_idx+1, r);
			return root;
		};

		return helper(0, N-1);
    }
};

void print(TreeNode* node){
	if (!node)
		return;
	cout << node->val << "->";
	print(node->left);
	print(node->right);
}

int main(){
    Solution sol;
	// vector<int> nums = {3,2,1,6,0,5};
	vector<int> nums = {3,2,1};
	TreeNode* res = sol.constructMaximumBinaryTree(nums);
	print(res);
	cout << "\n";
}
