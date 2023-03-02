#include <bits/stdc++.h>
using namespace std;
// TODO
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// TODO
class Solution {
private:
	int W, H;
public:
	vector<vector<string>> printTree(TreeNode* root) {
		function<int(TreeNode*,int)> getHeight = [&](TreeNode* node, int height){
			if (!node)
				return height;
			return max(getHeight(node->left,height+1), getHeight(node->right,height+1));
		};
		vector<vector<string>> res;
		H = getHeight(root,0);
		W = pow(2,H)-1;
		res.resize(H);
		cout << "width: " << W << "\theight: " << H << endl;
		for (int i = 0; i < H; i++)
			res[i].resize(W, "");
		
       	queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()){
			int breadth = q.size();
			 // cout << "breadth = " << breadth << endl;
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				 // cout << node->val << endl;
				if (node == root){
					int i = (W-1)/2;
					 // cout << "root i: " << i << endl;
					res[level][i] = to_string(root->val);
				}
				if (node->left){
					q.push(node->left);
					int i = W-pow(2,H-level-1);
					 cout << "left i: " << i << endl;
					res[level+1][i] = to_string(node->val);
				}
				if (node->right){
					q.push(node->right);
					int i = W+pow(2,H-level-1);
					 cout << "right i: " << i << endl;
					res[level+1][i] = to_string(node->val);
				}
			}
			level++;
		}

		return res;
    }
};

int main(){
    Solution sol;
	// TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr) ;
	// [["","1",""],
	//  ["2","",""]]
	//
	TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3)) ;
	// [["","1",""],
	//  ["2","","3"]]
	//
	vector<vector<string>> res = sol.printTree(root);
	for (vector<string> row : res){
		for (string cell : row)
			cout << cell;
		cout << "\n";
	}
}
