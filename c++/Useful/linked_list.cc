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

ListNode* genLinkedList(vector<int> nums){
	if (nums.size() == 0)
		return nullptr;
	else if (nums.size() == 1)
		return new ListNode(nums[0]);
	ListNode *head = new ListNode(nums[0]);
	ListNode *cursor = head;
	for (int i = 1; i < nums.size(); i++, cursor = cursor->next)
		cursor->next = new ListNode(nums[i]);
	return head;
}

void printLinkedList(ListNode* head){
	for (ListNode* cursor = head; cursor; cursor = cursor->next)
		cout << cursor->val << "->";
	cout << endl;
}

int main(){
	ListNode* res = genLinkedList({1,3,5,7,9,11});
	printLinkedList(res);	
}
