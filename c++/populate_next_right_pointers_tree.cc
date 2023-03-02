#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
private:
public:
	Node* connect(Node* root) {
   		queue<Node*> q;     
		q.push(root);
		while (!q.empty()){
			int breadth = q.size();
			Node* prev = nullptr;
			while (breadth--){
				Node* node = q.front(); q.pop();
				if (!node)
					break;
				if (prev)
					prev->next = node;
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
				prev = node;
			}
		}
		return root;
    }
};

void print(Node* root){
	Node* cursor = root;
	while (cursor){
		Node* row = cursor;
		while (row){
			cout << row->val << "->";
			row = row->next;
		}
		cout << "\n";
		cursor = cursor->left;
	}
}

int main(){
    Solution sol;
	Node* root = new Node(1, new Node(2, new Node(4), new Node(5), nullptr), new Node(3, new Node(6), new Node(7), nullptr), nullptr);
	Node* res = sol.connect(root);
	print(res);
}
