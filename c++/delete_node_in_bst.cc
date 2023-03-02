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
	TreeNode* deleteNode(TreeNode* root, int key) {
		function <TreeNode*(TreeNode*,TreeNode*,string)> dfs;
		dfs = [&](TreeNode* node, TreeNode* parent, string from) -> TreeNode* {
			if (not node)
				return nullptr;
			
			if (key < node->val)
				dfs(node->left, node, "right");
			else if (key > node->val)
				dfs(node->right, node, "left");
			else { // found match
				cout << "Found match: " << key << "\n";
				// if (not node->left and not node->right)
				// 	delete(node);

				// if (not node->left and node->right){
				// 	swap(node, node->right);
				// 	if (node->right)
				// 		delete node->right;
				// }
				// if (node->left and not node->right){
				// 	swap(node, node->left);
				// 	delete node->left;
				// }

				// if (node->left and node->right){
				// 	swap(node, node->right);
				// 	if (from == "left"){
				// 		parent->right = node;
				// 	} else { // right
				// 		parent->left = node;
				// 	}
				// 	if (node->right)
				// 		delete node->right;
				// }
			}


			return root;	
		};

		dfs(root, nullptr, "root");
		return root;
    }
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(7)));
	sol.deleteNode(root, 2);
}
