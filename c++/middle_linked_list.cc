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


// My intuition
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//   		int len = 0;      
// 		ListNode* cursor = head;
// 		while( (cursor = cursor->next) )
// 			len++;	
// 		int mid = (len % 2 != 0) ? (len/2)+1 : len/2;
// 		cursor = head;
// 		while (mid--)
// 			cursor = cursor->next;
// 		return cursor;
// 	}
// };

// Two pointers
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

int main(){
	Solution sol;
	// ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
	cout << sol.middleNode(head)->val;
}
