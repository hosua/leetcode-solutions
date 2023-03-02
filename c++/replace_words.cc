#include <bits/stdc++.h>
using namespace std;

#define ALPHA 26
struct TrieNode {
	TrieNode(bool end=false){
		for (int i = 0; i < ALPHA; i++)
			children[i] = nullptr;
	}
	TrieNode* children[ALPHA];
	bool end;
};

class Trie {
private:
	void addWordUtil(TrieNode* node, string word, int i=0){
		if (i == word.size()){
			node->end = true;
			return;
		}
		char ch = word[i];
		int ch_idx = ch-'a';
		TrieNode* child = node->children[ch_idx];

		if (child){
			addWordUtil(child, word, i+1);
		} else {
			child = new TrieNode();
		}
	}

	bool searchWordUtil(TrieNode* node, string word, int i=0){
		if (i == word.size()){
			return node->end == true;
		}
		char ch = word[i];
		int ch_idx = ch-'a';
		if (node->children[ch_idx] == 0){

		}
	}

public:
	Trie(){
		root = new TrieNode();	
	}
	TrieNode* root;
	void addWord(string word){
		addWordUtil(root, word);
	}

	bool searchWord(string word){

	}


};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

		Trie trie;		
		for (string word : dictionary){
			trie.addWord(word);		
		}
		return "";
    }
};

int main(){
	Solution sol;
	vector<string> dictionary = {"cat", "bat", "rat"};
	string sentence = "the cattle was rattled by the battery";
	string res = sol.replaceWords(dictionary, sentence);
	cout << res << endl;
}
