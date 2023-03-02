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

class BSTIterator {
	int i;
	vector<TreeNode*> v;
	public:
		
		BSTIterator(TreeNode* root) : i(0) {
			function <void(TreeNode*)> dfs = [&](TreeNode* node){
				if (not node)
					return;
				if (node->left)
					dfs(node->left);
				v.insert(v.begin(), node);
				i++;
				if (node->right)
					dfs(node->right);
			};
			dfs(root);
		}

		int next() {
			if (i > -1){
				v.pop_back();
				return v[--i]->val;
			}
			return -1;
		}

		bool hasNext() {
			return (v.size() > 0);
		}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main(){
	TreeNode* root = new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
	BSTIterator* itr = new BSTIterator(root);

	cout << itr->next() << "\n";
	cout << itr->next() << "\n";
	cout << itr->hasNext() << "\n";
	cout << itr->next() << "\n";
	cout << itr->hasNext() << "\n";
	cout << itr->next() << "\n";
	cout << itr->hasNext() << "\n";
	cout << itr->next() << "\n";
	cout << itr->hasNext() << "\n";
}
