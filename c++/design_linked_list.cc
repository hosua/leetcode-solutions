#include <bits/stdc++.h>
using namespace std;

// TODO: This question annoying af

struct Node {
	int val;
	Node* next;
	Node(int val): val(val), next(nullptr){}
};

class MyLinkedList {
public:
    MyLinkedList(): head(nullptr), tail(nullptr){}
    
    int get(int index) {
		cout << "get(" << index << ")\n";
		Node* cursor = head;
		for (int i = 0; i < index; i++, cursor=cursor->next)
			if (!cursor)
				return -1;
		return cursor->val;
    }
    
    void addAtHead(int val) {
		cout << "addHead(" << val << ")\n";
		Node* new_node = new Node(val);
       	if (!head){
			head = tail = new_node;
		} else {
			new_node->next = head;	
			head = new_node;
		}
    }
    
    void addAtTail(int val) {
		cout << "addTail(" << val << ")\n";
		Node* new_node = new Node(val);
		if(!tail){
			head = tail = new_node;
		} else { 
			tail->next = new_node;
			tail = new_node;
		}
    }
    
    void addAtIndex(int index, int val) {
		cout << "addIndex(" << index << " " << val << ")\n";
		Node* new_node = new Node(val);
		Node* prev = nullptr;
		Node* cursor = head;
       	for (int i = 0; i < index; i++, prev=cursor, cursor=cursor->next){
			if (!cursor)
				return;
		} 
		if (prev)
			prev->next = new_node;
		else
			head = new_node;
		new_node->next = cursor;
    }
    
    void deleteAtIndex(int index) {
		cout << "delIndex(" << index << ")\n";
		Node* prev = nullptr;
		Node* cursor = head;
       	for (int i = 0; i < index; i++, prev=cursor, cursor=cursor->next){
			if (!cursor)
				return;
		} 
		if (prev)
			prev->next = cursor->next;
		else
			head = cursor->next;
		delete cursor;

		if (!head)
			tail = head;
    }
private:
	Node* head;
	Node* tail;
};


int main(){
    MyLinkedList ll;
	ll.addAtHead(7);
	ll.addAtTail(2);
	ll.addAtTail(1);
	ll.addAtIndex(3, 0);
	ll.deleteAtIndex(2);
	ll.addAtHead(6);
	ll.addAtTail(4); // Problem here
	cout << ll.get(4) << "\n";
	ll.addAtHead(4);
	ll.addAtIndex(5,0);
	ll.addAtHead(6);
}
