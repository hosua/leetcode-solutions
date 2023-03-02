#include <bits/stdc++.h>
using namespace std;


// I FAILED 
#define ALPHA 26
class Trie {
private:
	struct Node {
		array<Node*, ALPHA> children;	
		bool is_end;
		Node(): is_end(false){
			for (Node*& node : children)
				node = nullptr;
		}
	};

public:
	Trie(): root(new Node){}
	void insert(string word){
		Node* node = root;
		for (int i =0; i < word.size(); i++){
			char ch = word[i];	
			char chidx = ch - 'a';
			if (!node->children[chidx])
				node->children[chidx] = new Node();
			node = node->children[chidx];
		} 
		node->is_end = true;
	}

	int countSubsequences(string word){
		int count = 0;
		Node* node = root;
		for (int i = 0; i < word.size(); i++){
			char ch = word[i];
			char chidx = ch - 'a';
			cout << i << "(" << ch << ")\n";
			if (node->children[chidx]){
				if (node->children[chidx]->is_end)
					count++;
				node = node->children[chidx];
			}
		};
		return count;
	}

	Node* root;
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       	Trie trie;
		for (string word : words)
			trie.insert(word);
		return trie.countSubsequences(s);
    }
};

int main(){
    Solution sol;
	string s = "abcde";
	vector<string> words = {"a","bb","acd","ace"};
	int res = sol.numMatchingSubseq(s, words);
	cout << res << "\n";
}
