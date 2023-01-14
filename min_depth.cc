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
    int minDepth(TreeNode* root) {
		if (!root)
			return 0;

    	queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()){
			level++;
			int breadth = q.size();
			for (int i = 0; i < breadth; i++){
				TreeNode* node = q.front();
				q.pop();
				if (!node) 
					continue;
				if (!node->left && !node->right)
					return level;
				q.push(node->left);
				q.push(node->right);
			}
		}
		return -1;
    }
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	cout << sol.minDepth(root);
}
