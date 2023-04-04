#include <bits/stdc++.h>
using namespace std;

#define ALPHA 26

class Node {
	Node(){
		for (int i = 0; i < ALPHA; i++)
			children[i] = nullptr;
		is_end = false;
	}
	array<Node*, ALPHA> children;
	bool is_end;
};

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
	Trie trie;

}
