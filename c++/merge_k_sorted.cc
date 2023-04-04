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
private:
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *lst, *node, *curr_lst;
		curr_lst = lst = node = nullptr;
		
		while ( (node=getNextLowest(lists)) ){
			if (!lst){
				lst = curr_lst = node;
			} else {
				curr_lst->next = node;
				curr_lst = curr_lst->next;
			}
		}
		if (curr_lst)
			curr_lst->next = nullptr;
		return lst;
	}

	ListNode* getNextLowest(vector<ListNode*>& lists){
		int curr_lowest = INT_MAX, curr_idx = -1;

		for (int i = 0; i < lists.size(); i++){
			ListNode* cursor = lists[i];
			if (cursor && cursor->val < curr_lowest){
				curr_idx = i;
				curr_lowest = cursor->val;
			}
		}

		if (curr_idx != -1){
			ListNode* res = lists[curr_idx];
			lists[curr_idx] = lists[curr_idx]->next;
			return res;
		}
		return nullptr;
	}
};

int main(){
    Solution sol;
	ListNode* zero = new ListNode(1, new ListNode(4, new ListNode(5)));
	ListNode* one = new ListNode(1, new ListNode(3, new ListNode(4)));
	ListNode* two = new ListNode(2, new ListNode(6));
	vector<ListNode*> lists = {zero, one, two};

	ListNode* res = sol.mergeKLists(lists);

	for (ListNode* cursor = res; cursor; cursor = cursor->next){
		cout << cursor->val << "->";
	}
	cout << "\n";
}
