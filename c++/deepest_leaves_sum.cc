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
    int deepestLeavesSum(TreeNode* root) {
  		queue<TreeNode*> q;
		q.push(root);
		int sum = 0;
		while (!q.empty()){
			sum = 0;
			int breadth = q.size();
			vector<int> level;
			while (breadth--){
				TreeNode* node = q.front();
				q.pop();
				sum += node->val;
				level.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		return sum;
    }
};
int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(7), nullptr), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(6, nullptr, new TreeNode(8))));
	int res = sol.deepestLeavesSum(root);
	cout << res << endl;
}
