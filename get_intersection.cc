#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
	set<ListNode*> seen_set;
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		return helper(headA, headB);
	}

	ListNode* helper(ListNode* a, ListNode* b){
		if (!a && !b)
			return nullptr;
		if (a){
			if (seen_set.find(a) != seen_set.end())
				return a;
			seen_set.insert(a);
			return helper(a->next, b);
		}

		if (b){
			if(seen_set.find(b) != seen_set.end())
				return b;
			seen_set.insert(b);
			return helper(a, b->next);
		}

		return nullptr;
	}
};

int main(){
	ListNode* n1 = new ListNode(1); // a
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(-5);
	ListNode* n7 = new ListNode(-6);
	ListNode* n8 = new ListNode(-7);

	n1->next = n2; // n1 = a
	n2->next = n3;

	n4->next = n6; // n4 = b
	n6->next = n5;
	n5->next = n3;
	n3->next = n7;
	n7->next = n8;
	// intersection at n3
	Solution sol;
	cout << sol.getIntersectionNode(n1, n4)->val;
}
