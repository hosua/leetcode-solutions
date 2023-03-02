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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
   		function <void()> bfs = [&](){
			queue<TreeNode*> q;
			q.push(root);

			while (not q.empty()){
				int breadth = q.size();
				TreeNode* node = nullptr;
				while (breadth--){
					node = q.front(); q.pop();
					if (node){
						if (node->left)
							q.push(node->left);
						if (node->right)
							q.push(node->right);
					}
				}
				if (node)
					res.push_back(node->val);
			}	
		};
		bfs();
		return res;
    }
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(6, new TreeNode(7), nullptr), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(4)));
	vector<int> res = sol.rightSideView(root);
	for (int num : res)
		cout << num << " ";
	cout << "\n";
}
