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
private:
public:
	int maxLevelSum(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
    	int max_sum = INT_MIN, res = 0;    
		int level = 0;
		while (!q.empty()){
			level++;
			int breadth = q.size();
			int row_sum = 0;
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				row_sum += node->val;
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			if (row_sum > max_sum){
				max_sum = row_sum;
				res = level;
			}
		}
		return res;
    }
};

int main(){
    Solution sol;
	// TreeNode* root = new TreeNode(1, new TreeNode(7, new TreeNode(7), new TreeNode(-8)), new TreeNode(0));
	TreeNode* root = new TreeNode(-100, new TreeNode(-200, new TreeNode(-20), new TreeNode(-5)), new TreeNode(-300, new TreeNode(-10), nullptr));
	int res = sol.maxLevelSum(root);
	cout << res << endl;
}
