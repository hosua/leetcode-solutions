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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
  		queue<TreeNode*> q;      
		if (root)
			q.push(root);
		int level = 1;
		bool left_right = true;
		while (not q.empty()){
			int breadth = q.size();
			if (breadth){
				res.resize(level);
				while (breadth--){
					TreeNode* node = q.front(); q.pop();
					int val = node->val;
					res[level-1].push_back(val);
					if (node->left)
						q.push(node->left);
					if (node->right)
						q.push(node->right);
				}
				if (not left_right) 
					reverse(res[level-1].begin(), res[level-1].end());
			}
			left_right = (left_right) ? false : true;
			level++;
		}
		return res;
    }
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	vector<vector<int>> res = sol.zigzagLevelOrder(root);
	for (vector<int> level : res){
		for (int val : level)
			cout << val << " ";
		cout << "\n";
	}
}
