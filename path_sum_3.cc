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
	int num_paths;
public:
    int pathSum(TreeNode* root, int targetSum) {
		num_paths = 0;
   		DFS(root, 0, targetSum);    	 
		cout << endl;
		return num_paths;
    }

	void DFS(TreeNode* node, double sum, int targetSum, vector<int> path={}, bool flag=false){
		if (!node)
			return;
		int val = node->val;
		sum += val;
		path.push_back(val);
		if (targetSum == sum){
			if (targetSum != 0)
				num_paths++;
			else if (flag){
				if (sum == 0)
					num_paths++;	
			} else if (val == 0){
				num_paths++;
			}
		}

		double s = sum;
		for (int i = 0; i < path.size()-1; i++){
			s -= path[i]; 
			if (s == targetSum){
				if (targetSum != 0)
					num_paths++;
				else if (flag and s == 0){
					num_paths++;	
				}
			}
		}
		// cout << endl;
		DFS(node->left, sum, targetSum, path, true);
		DFS(node->right, sum, targetSum, path, true);
	}
};

int main(){
	Solution sol;
	// TreeNode* root = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, nullptr, new TreeNode(1))), new TreeNode(-3, nullptr, new TreeNode(11)));
	// int targetSum = 8;
	// TreeNode* root = new TreeNode(1);
	// int targetSum = 0; // 0 
	// TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);
	// int targetSum = 0; // 0
	// TreeNode* root = new TreeNode(1, new TreeNode(0), nullptr);
	// int targetSum = 0; // 1
	// TreeNode* root = new TreeNode(0, new TreeNode(1), new TreeNode(1));
	// int targetSum = 1; // 4
	TreeNode* root = new TreeNode(0, new TreeNode(1), new TreeNode(1));
	int targetSum = 0; // 1
	int res = sol.pathSum(root, targetSum);
	cout << res << endl;
}
