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
    ListNode* mergeNodes(ListNode* head) {
		ListNode *res = nullptr, *res_cursor = nullptr;        
		int curr_sum = 0;
		for (ListNode* cursor = head; cursor; cursor = cursor->next){
			if (cursor->val == 0 && curr_sum){
				ListNode* new_node = new ListNode(curr_sum);
				if (!res)
					res = res_cursor = new_node;
				else {
					res_cursor->next = new_node;
					res_cursor = res_cursor->next;
				}
				curr_sum = 0;
			} else
				curr_sum += cursor->val;
		}

		return res;
    }
};

int main(){
	Solution sol;
	ListNode* head = new ListNode(0, new ListNode(3, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(0))))))));
	ListNode* res = sol.mergeNodes(head);
	for (ListNode* cursor = res; cursor; cursor = cursor->next)
		cout << cursor->val << "->";
	cout << "\n";
}
