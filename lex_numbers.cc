#include <bits/stdc++.h>
using namespace std;

#define NUM_DIGITS 10

class Node {
public:
	Node(){
		for (int i = 0; i < NUM_DIGITS; i++)
			children[i] = nullptr;
	}
	Node* children[NUM_DIGITS];
};

class Trie {
private:
	Node* root;

public:
	Trie(){
		root = new Node();
	}

	void insertNode(int num){
		string num_str = to_string(num);	
		Node* crawl = root;
		for (char ch : num_str){
			int ch_idx = ch - '0';
			if (!crawl->children[ch_idx]){
				crawl->children[ch_idx] = new Node();
			}
			crawl = crawl->children[ch_idx];
		}
	}

	void fillTrie(int n){
		for (int i = 1; i <= n; i++){
			insertNode(i);	
		}
	}

	vector<int> getVec(){
		vector<int> res;
	}
	void BFS(){
		queue<Node*> q;	
		q.push(root);
		while(!q.empty()){
		}
	}
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
		vector<int> res;
		Trie* trie;
    	trie->fillTrie(n); 
		return res;
    }
};

int main(){
	Solution sol;
	sol.lexicalOrder(5);
}
