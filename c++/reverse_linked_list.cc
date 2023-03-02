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
public:
    ListNode* reverseList(ListNode* head) {
		ListNode *cursor = head, *prev = nullptr, *next = nullptr;
		while (cursor){
			next = cursor->next;
			cursor->next = prev;
			prev = cursor;
			cursor = next;
		}
		return prev;
    }

	void print(ListNode* head){
		while(head){
			cout << head->val << "->";
			head = head->next;	
		}	
		cout << endl;
	}
};

int main(){
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
	Solution sol;
	sol.print(head);
	head = sol.reverseList(head);
	sol.print(head);
}
