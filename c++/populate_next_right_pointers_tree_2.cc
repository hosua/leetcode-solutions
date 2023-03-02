#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
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
		while (not q.empty()){
			int breadth = q.size();
			vector<Node*> level_nodes;
			while(breadth--){
				Node* node = q.front(); q.pop();
				if (not node)
					break;
				level_nodes.push_back(node);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			Node* prev = nullptr;
			for (Node* node : level_nodes){
				if (prev)
					prev->next = node;
				prev = node;
			}
		}
		return root;
    }
};

void printLevelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	while (not q.empty()){
		int breadth = q.size();
		while(breadth--){
			Node* node = q.front(); q.pop();
			cout << node->val << " ";
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		cout << "\n";
	}
}

void printRightNodes(Node* root){
	queue<Node*> q;
	q.push(root);
	cout << root->val << "\n";
	while (!q.empty()){
		int breadth = q.size();
		Node* node = q.front(); q.pop();
		vector<Node*> level_nodes;
		while (breadth--){
			if (node->left){
				q.push(node->left);
				level_nodes.push_back(node->left);
			}
			if (node->right){
				q.push(node->right);
				level_nodes.push_back(node->right);
			}
		}
		Node* cursor = (level_nodes.size() > 0) ? level_nodes[0] : nullptr;
		while (cursor){
			cout << cursor->val << " ";
			cursor = cursor->next;
		}
		cout << "\n";
	}

}

int main(){
    Solution sol;
	Node* root = new Node(1, new Node(2, new Node(4), new Node(5), nullptr), new Node(3, nullptr, new Node(7), nullptr), nullptr);
	Node* res = sol.connect(root);
	// printLevelOrder(root);
	printRightNodes(root);
}
