#include <stdio.h> 

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       	ListNode* output = nullptr; 
		ListNode* c1 = l1;
		ListNode* c2 = l2;
		int val1, val2;
		bool carry = false;
		while (true) {
			if (!c1 && !c2){
				if (carry){
					ListNode* new_node = new ListNode(1);
					new_node->next = output;
					output = new_node;
				}
				break;
			}
			val1 = val2 = 0;
			if (c1){
				val1 = c1->val;
				c1 = c1->next;	
			}
			if (c2){
				val2 = c2->val;
				c2 = c2->next;	
			}
			printf("v1: %i\t", val1); 
			printf("v2: %i\t", val2); 
			printf("\n");	
			int digit = val1 + val2;
			if (carry)
				digit++;
			
			if (digit > 9){
				carry = true;	
				digit -= 10;
			} else {
				carry = false;
			}
			if (!output){
				output = new ListNode(digit);
			} else {
				ListNode* new_node = new ListNode(digit);
				new_node->next = output;
				output = new_node;
			}
		}
		reverse(&output);
		return output;
    }

	void reverse(ListNode** head){
		ListNode* temp = nullptr;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		ListNode* curr = *head;
		while (curr){
			temp = curr->next;
			curr->next = prev;
			prev = curr;	
			curr = temp;
		}
		*head = prev;
	}
};

void printNodes(ListNode* head){
	for ( ; head; head = head->next)
		printf("%i->", head->val);
	printf("\n");
}


int main(){
	Solution sol;
	ListNode l1;
	l1.val = 9;
	l1.next = new ListNode(9);
	l1.next->next = new ListNode(9);
	l1.next->next->next = new ListNode(9);
	l1.next->next->next->next = new ListNode(9);
	l1.next->next->next->next->next = new ListNode(9);
	l1.next->next->next->next->next->next = new ListNode(9);
	printNodes(&l1);
	ListNode l2;	
	l2.val = 9;
	l2.next = new ListNode(9);
	l2.next->next = new ListNode(9);
	l2.next->next->next = new ListNode(9);
	printNodes(&l2);
	ListNode* res = sol.addTwoNumbers(&l1, &l2);
	printNodes(res);

}
