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
private:
public:
	ListNode* swapPairs(ListNode* head) {

		return head;
    }
};

int main(){
    Solution sol;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
	printList(head);
	ListNode* res = sol.swapPairs(head);
	printList(res);
}
