#include <bits/stdc++.h>
using namespace std;

/* 
push
1 2 3 4
buf 1 2 3 4 | 5
q_stack 4 3 2 1 
buf 1 2 3 4 | 5
q_stack 5 4 3 2 1

pop
q_stack 5 4 3 2 1

*/

class MyQueue {
	stack<int> buf;
	stack<int> q_stack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       	while (!q_stack.empty()){
			buf.push(q_stack.top());		
			q_stack.pop();
		} 
		buf.push(x);
		while (!buf.empty()){
			q_stack.push(buf.top());
			buf.pop();
		}
    }
    
    int pop() {
       	int t = q_stack.top(); 
		q_stack.pop();
		return t;
    }
    
    int peek() {
       	return q_stack.top(); 
    }
    
    bool empty() {
       	return (q_stack.empty()); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(){
	MyQueue q;

}
