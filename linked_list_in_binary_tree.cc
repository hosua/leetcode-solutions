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
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
	bool isSubPath(ListNode* head, TreeNode* root) {
    	function <bool(ListNode*,TreeNode*)> isSub;
		function <bool(ListNode*,TreeNode*)> dfs;

		isSub = [&](ListNode* lnode, TreeNode* tnode) -> bool {
			if (not lnode)
				return true;
			if (not tnode or tnode->val != lnode->val)
				return false;

			bool left = false, right = false;
			if (lnode->val == tnode->val){
				left = isSub(lnode->next, tnode->left);
				right = isSub(lnode->next, tnode->right);
			}

			return left or right;
		};

		dfs = [&](ListNode* lnode, TreeNode* tnode) -> bool {
			if (not tnode)
				return false;

			bool left = dfs(lnode, tnode->left);
			if (lnode->val == tnode->val and isSub(lnode, tnode)){
				return true;
			}
			bool right = dfs(lnode, tnode->right);
			return left or right;
		};

		return dfs(head, root);
    }
};

int main(){
    Solution sol;
	ListNode* head = new ListNode(2, new ListNode(8, new ListNode(2)));
	TreeNode* root = new TreeNode(1, new TreeNode(4, nullptr, new TreeNode(2, new TreeNode(1), nullptr)), new TreeNode(4, new TreeNode(2, new TreeNode(6), new TreeNode(8, new TreeNode(1), new TreeNode(3))), nullptr));
	bool res = sol.isSubPath(head, root);
	cout << res << endl;
}
