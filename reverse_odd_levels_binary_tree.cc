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
	TreeNode* reverseOddLevels(TreeNode* root) {
   		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()){
			int breadth = q.size();
			vector<TreeNode*> level_nodes;
			stack<int> s;
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				s.push(node->val);
				level_nodes.push_back(node);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			if (level % 2 != 0){
				int i = 0;
				while (!s.empty()){
					level_nodes[i++]->val = s.top(); 
					s.pop();
				}
			}
			level++;
		}
		return root;
    }
};

void levelOrder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()){
		int breadth = q.size();
		while (breadth--){
			TreeNode* node = q.front(); q.pop();
			cout << node->val << " ";
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		cout << "\n";
	}
	cout << "------\n";
}

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(2, new TreeNode(3, new TreeNode(8), new TreeNode(13)), new TreeNode(5, new TreeNode(21), new TreeNode(34)));
	levelOrder(root);
	sol.reverseOddLevels(root);
	levelOrder(root);
}
