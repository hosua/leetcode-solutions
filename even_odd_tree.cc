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
	bool isEvenOddTree(TreeNode* root) {
   		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (not q.empty()){
			int breadth = q.size();
			int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				int val = node->val;
				if (level % 2 == 0 and (val % 2 == 0 or val <= prev))
					return false;
				else if (level % 2 != 0 and (val % 2 != 0 or val >= prev))
					return false;
				prev = val;
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			level++;
		}
		return true;
    }
};

int main(){
    Solution sol;
	// TreeNode* root = new TreeNode(1, new TreeNode(10, new TreeNode(3, new TreeNode(12), new TreeNode(8)), nullptr), new TreeNode(4, new TreeNode(7, new TreeNode(6), nullptr), new TreeNode(9, nullptr, new TreeNode(2))));
	// 1
	TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(3), new TreeNode(3)), new TreeNode(2, new TreeNode(7), nullptr));
	// 0
	bool res  = sol.isEvenOddTree(root);
	cout << res << endl;
}
