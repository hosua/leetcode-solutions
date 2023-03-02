#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	set<ListNode*> addrs;
public:
    ListNode *detectCycle(ListNode *head) {
		int i = 0;
		for (ListNode* cursor = head; cursor; cursor = cursor->next, i++){
			if (addrs.find(cursor) == addrs.end())
				addrs.insert(cursor);
			else
				return cursor;		
		}
		return nullptr;
    }
};
int main(){
	Solution sol;
	ListNode* c = new ListNode(2);
	ListNode* head = new ListNode(3);
	head->next = c;
	c->next = new ListNode(0);
	c->next->next = new ListNode(-4);
	c->next->next->next = c;
	ListNode* res = sol.detectCycle(head);
	cout << res->val << endl;
}
