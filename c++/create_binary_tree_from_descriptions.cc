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
  	TreeNode* root;      
	unordered_map<int, pair<int, TreeNode*>> mp;  // <key, <parent_count, addr>>

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		for (vector<int> desc : descriptions){
			int parent = desc[0], child = desc[1], is_left = desc[2];

			int &freq = mp[parent].first;
			TreeNode* par_node = nullptr;
			if (mp.find(parent) == mp.end()){
				mp[parent].second = new TreeNode(parent);
			}
			par_node = mp[parent].second;
			TreeNode* child_node = nullptr;
			if (mp.find(child) == mp.end()){
				mp[child].second = new TreeNode(child);
			}
			child_node = mp[child].second;
		}

		for (auto& [key, val] : mp){
			auto& [freq, node] = val;
			if (freq == 0){
				root = node;
				break;
			}
		}
		
		dfs(root);
		return root;
    }

private:
	void dfs(TreeNode* node){
		if (!root)
			return;
		cout << root->val << "->";
		dfs(root->left);
		dfs(root->right);
	}
};


int main(){
    Solution sol;
	vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
	TreeNode* res = sol.createBinaryTree(descriptions);
	// cout << res << "\n";
	// sol.dfs(res);
}
