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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode*> res;
		set<vector<int>> s;
       	function <void(TreeNode*,vector<int>)> dfs; 
		dfs = [&](TreeNode* node, vector<int> subtree){
			if (not node)
				return;
			dfs(node->left, subtree);
			dfs(node->right, subtree);

			if (find(res.begin(), res.end(), node) == res.end()){
				// cout << "Adding node " << node->val << "\n";
				// cout << subtree.size() << "\n";
				for (int num : subtree)
					cout << num << " ";
				cout << "\n";
				res.push_back(node);
			}
		};
		dfs(root, {});
		return res;
    }
};

void printList(TreeNode* root){
	if (not root)
		return;

	printList(root->left);
	cout << root->val << "->";
	printList(root->right);
}

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(4)));
	vector<TreeNode*> res = sol.findDuplicateSubtrees(root);
	for (TreeNode* rt : res){
		printList(rt);
		cout << "\n";
	}
}
