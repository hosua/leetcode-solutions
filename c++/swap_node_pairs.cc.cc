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

class Solution {
	int i;
public:
	Solution():i(0){}
    ListNode* swapPairs(ListNode* head) {
		// I suck
    }
};

void printList(ListNode* head){
	while (head){
		cout << head->val << "->";
		head = head->next;
	}
	cout << endl;
}

int main(){
	Solution sol;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
	head = sol.swapPairs(head);
	printList(head);
}
