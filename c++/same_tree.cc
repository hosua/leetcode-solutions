// https://leetcode.com/problems/same-tree/


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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
			return true;
		if ((!p && q) || (p && !q))
			return false;
		if (p->val != q->val)
			return false;

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
	Solution sol;
	TreeNode pl = TreeNode(2);
	TreeNode pr = TreeNode(3);
	TreeNode p = TreeNode(1, &pl, &pr);
	TreeNode q = TreeNode(1, &pl, &pr);
	bool res = sol.isSameTree(&p, &q);
	cout << res << endl;
}
