#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};

ListNode* reverseLinkedList (ListNode* head) {
    // add your logic here
	ListNode *cursor = head, *next = NULL, *prev = NULL;
	while (cursor){
		next = cursor->next;	
		cursor->next = prev;
		prev = cursor;
		cursor = next;
	}
	head = prev;
	return head;
}

int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

}
