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

// In the future when coming up with a solution, try printing out the different order traversals and see if a useful pattern is available.
// The idea for this problem is that we know that the BST can be looked at as an array with its elements in order.
// Since the elements are in order, doing an inorder traversal and comparing adjacent node values would have been the ideal way to do this.
// My mistake at first was not doing an DFS inorder traversal, I did a DFS preorder traversal, which breaks the order of the BST.
class Solution {
	int min_dist;
	TreeNode* prev;
public:
    int minDiffInBST(TreeNode* root) {
		min_dist = INT_MAX;
		inorder(root);
		return min_dist;
	}

	void inorder(TreeNode* node){
		if (!node)
			return;
		inorder(node->left);
		if (prev)
			min_dist = min(min_dist, abs(node->val - prev->val));
		prev = node;
		inorder(node->right);
	}
	// This solution is horrible lol
    // int minDiffInBST(TreeNode* root) {
	//	set<int> vals;
	// 	int left, right;
	// 	left = right = INT_MAX;
	// 	vals.insert(root->val);
	// 	if (root->left){
	// 		left = abs(root->val - root->left->val);
	// 		left = min(left, minDiffInBST(root->left));
	// 	}
	// 	if (root->right){
	// 		right = abs(root->val - root->right->val);
	// 		right = min(right, minDiffInBST(root->right));
	// 	}
	// 	int l_diff, r_diff;
	// 	l_diff = r_diff = INT_MAX;
	// 	set<int>::iterator l = vals.find(root->val);
	// 	if (l != vals.begin()){
	// 		l--;
	// 		l_diff = abs(*l - root->val);
	// 	}

	// 	set<int>::iterator r = vals.find(root->val);
	// 	if (r != vals.end()){
	// 		r++;
	// 		r_diff = abs(*r - root->val);
	// 	}

	// 	return min({l_diff, left, right, r_diff});
    // }
};


void printInorder(TreeNode* root){
	if (!root)
		return;
	
	printInorder(root->left);
	cout << root->val << "->";
	printInorder(root->right);
}

void printLevelOrder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()){
		size_t breadth = q.size();
		while (breadth--){
			TreeNode* node = q.front(); q.pop();
			if (node){
				cout << node->val << " ";	
				q.push(node->left);
				q.push(node->right);
			} else {
				cout << " * ";
			}
		}
		cout << "\n";
	}
}

int main(){
    Solution sol;
	// TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(6)); // 1
	TreeNode* root = new TreeNode(90, new TreeNode(69, new TreeNode(49, nullptr, new TreeNode(52)), new TreeNode(89)), nullptr); // 1
	// TreeNode* root = new TreeNode(5, new TreeNode(1), new TreeNode(7));
	// printInorder(root);
	int res = sol.minDiffInBST(root);
	cout << res << "\n";
}
