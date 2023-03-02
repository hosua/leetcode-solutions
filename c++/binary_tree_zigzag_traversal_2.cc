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
 		queue<TreeNode*> q;       
		q.push(root);

		vector<vector<int>> res;
		int level = 0;
		while (!q.empty()){
			res.resize(level+1);
			size_t breadth = q.size();
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				if (node){
					if (level % 2 == 0)
						res[level].push_back(node->val);
					else
						res[level].insert(res[level].begin(), node->val);
					q.push(node->left);
					q.push(node->right);
				}
			}
			level++;
		}
		res.resize(level-1);
		return res;
    }
};
int main(){
    Solution sol;
	TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	vector<vector<int>> res = sol.zigzagLevelOrder(root);
	for (vector<int> row : res){
		for (int num : row)
			cout << num << " ";
		cout << "\n";
	}
}
