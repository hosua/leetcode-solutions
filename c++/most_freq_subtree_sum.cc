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
	int max_freq;
	map<int,int> mp; // <sum, freq>
public:
	Solution() : max_freq(INT_MIN){}
    vector<int> findFrequentTreeSum(TreeNode* root) {
    	vector<int> res;

		function <int(TreeNode*)> subTreeSum = [&](TreeNode* node) -> int {
			if (not node)
				return 0;
			return subTreeSum(node->left) + node->val + subTreeSum(node->right);
		};
		
		function <void(TreeNode*)> dfs = [&](TreeNode* node) -> void {
			if (not node)
				return;

			dfs(node->left);
			dfs(node->right);

			int curr_sum = subTreeSum(node);
			mp[curr_sum]++;
			max_freq = max(max_freq, mp[curr_sum]);	
		};

		dfs(root);

		for (map<int,int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
			if (max_freq == itr->second)
				res.push_back(itr->first);
		}
		return res;
    }
};

int main(){
	Solution sol;
	// TreeNode* root = new TreeNode(5, new TreeNode(2), new TreeNode(-3));
	TreeNode* root = new TreeNode(3, new TreeNode(1, new TreeNode(0), new TreeNode(2, new TreeNode(3), nullptr)), new TreeNode(5, new TreeNode(4), new TreeNode(6)));
	vector<int> res = sol.findFrequentTreeSum(root);
	cout << "\n";
	for (int num : res)
		cout << num << " ";
	cout << endl;

}
