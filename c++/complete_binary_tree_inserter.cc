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

class CBTInserter {
	TreeNode* root;
public:
    CBTInserter(TreeNode* root=nullptr) : root(root) {}
    
    int insert(int val) {
		if (!root){
			root = new TreeNode(val);
			return -1;
		}

       	queue<TreeNode*> q; 
		q.push(root);

		while (!q.empty()){
			size_t breadth = q.size();
			while(breadth--){
				TreeNode* node = q.front(); q.pop();
				if (!node->left){
					node->left = new TreeNode(val);
					return node->val;
				}
				if (!node->right){
					node->right = new TreeNode(val);
					return node->val;
				}
				q.push(node->left);
				q.push(node->right);
			}
		}
		return -1;
    }
    
    TreeNode* get_root() {
       	return root; 
    }
};

int main(){
    CBTInserter cbt;
	cbt.insert(1);
	cbt.insert(2);
	cbt.insert(3);
	cbt.insert(4);
}
