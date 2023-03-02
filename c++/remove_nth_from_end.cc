#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* node){
	if (not node){
		cout << "\n";
		return;
	}
	cout << node->val << "->";
	printList(node->next);	
}


class Solution {
	int sz;
public:
	Solution() : sz(0){}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
	}
};

int main(){
	Solution sol;
	// ListNode* root = new ListNode(1, new ListNode(2, new ListNode (3, new ListNode (4, new ListNode(5)))));
	// int n = 2; // -> [1,2,3,5]
	// int n = 1; // -> [1,2,3,4]
	// ListNode* root = new ListNode(1);
	// int n = 1; // -> []
	ListNode* root = new ListNode(1, new ListNode(2));
	int n = 1; // -> [1]
	// printList(root);
	root = sol.removeNthFromEnd(root, n);
	if (root)
		printList(root);
	else
		cout << "empty list\n";
}
