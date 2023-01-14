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

// Yay me!

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next || !head->next->next)
			return head;
		ListNode *odd = head;
		ListNode *even = head->next;
		ListNode *e_start = even;
		ListNode *t1 = nullptr, *t2 = nullptr;
		while(odd && odd->next && even && even->next){
			if (t1)
				t1->next = odd;
			if (t2)
				t2->next = even;
			t1 = odd, t2 = even;
			odd = odd->next->next;
			even = even->next->next;
		}
		t1->next = odd;
		(even) ? t2->next = even : t2->next = nullptr;
		
		odd->next = e_start;
		even = nullptr;
		return head;
    }
};

int main(){
	Solution sol;
	// ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	// expect: [1,3,5,2,4]
	// ListNode* head = new ListNode(2, new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(7)))))));
	// expect: [2,3,6,7,1,5,4]
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8))))))));
	// expect: [1,3,5,7,2,4,6,8]
	ListNode* res = sol.oddEvenList(head);
	int i = 0;
	for (ListNode* cursor = res; cursor; cursor = cursor->next){
		cout << cursor->val << "->";
	}
	cout << "\n";
}
