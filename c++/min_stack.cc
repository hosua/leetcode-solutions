#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* next;
	int val;
	Node(int val, Node* next=nullptr){
		this->next = next;
		this->val = val;	
	}
};

class MinStack {
	Node* head;
	map<int, int> freq_map;
public:
    MinStack() {
       	head = nullptr;
    }
    
    void push(int val) {
		if (freq_map.find(val) == freq_map.end()){
			freq_map.insert( {val, 1} );
		} else {
			freq_map[val]++;
		}
		Node* new_node = new Node(val);

       	if (head){
			new_node->next = head;
		} 
		head = new_node;
    }
    
    void pop() {
       	Node* temp = head;
		int val = temp->val;
		freq_map[val]--;
		if (freq_map.find(val) != freq_map.end() && freq_map[val] == 0){
			freq_map.erase(val);
		}
		head = head->next;
		delete temp;
    }
    
    int top() {
       	return head->val; 
    }
    
    int getMin() {
       	return freq_map.begin()->first; 
    }

	void print(){
		for (Node* cursor = head; cursor; cursor = cursor->next)
			cout << cursor->val << " ";
		cout << endl;
	}
};



int main(){
	MinStack sol;
	sol.push(0);
	sol.push(1);
	sol.push(0);
	cout << sol.getMin() << endl;
	sol.pop();
	cout << sol.getMin() << endl;
}
