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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root)
			return {};
   		vector<vector<int>> res;
		stack<vector<int>> s;
		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()){
			vector<int> row;
			size_t breadth = q.size();
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				row.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			s.push(row);
		}
		while (!s.empty()){
			res.push_back(s.top()); s.pop();
		}
		return res;
    }
};

int main(){
    Solution sol;
	// TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	TreeNode* root = nullptr;
	// TreeNode* root = new TreeNode(1);
	vector<vector<int>> res = sol.levelOrderBottom(root);
	for (vector<int> row : res){
		for (int num : row)
			cout << num << " ";
		cout << "\n";
	}
}
