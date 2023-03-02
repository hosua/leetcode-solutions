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
	vector<TreeNode*> res;
	unordered_map<string, pair<TreeNode*, int>> mp;
    function <string(TreeNode*)> dfs; 
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs = [&](TreeNode* node) -> string{
			if (not node)
				return "*";
			string subtree = to_string(node->val) + ": [" + dfs(node->left) + "," + dfs(node->right) + "]";
			if (subtree != "[*,*]")
				mp[subtree] = {node, mp[subtree].second+1};
			return subtree;
		};
		dfs(root);

		for (auto [str, p] : mp){
			auto [node, freq] = p;
			if (freq > 1)
				res.push_back(node);
		}
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
