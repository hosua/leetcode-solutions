#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		Node(){
			is_end = false;
			for (int i = 0; i < 26; i++){
				children[i] = NULL;
			}
		}
		Node* children[26];
		bool is_end; // end of word
};

class Trie {
	private:
		int char_index(char ch){
			return tolower(ch) - 'a';
		}
	public:
		Node* root;

		Trie() {
			root = new Node();
		}

		void insert(string word) {
			Node* crawl = root;
			for (char ch : word){
				int ch_idx = char_index(ch);
				// Add new char node if inexistent
				if (!crawl->children[ch_idx]){
					crawl->children[ch_idx] = new Node();
				}
				// crawl to the next node, new or not
				crawl = crawl->children[ch_idx];
			} 
			crawl->is_end = true;
		}

		bool search(string word) {
			Node* crawl = root;
			for (char ch : word){
				int ch_idx = char_index(ch);
				// If the node is null then the word is not in the trie
				if (!crawl->children[ch_idx])
					return false;
				crawl = crawl->children[ch_idx];
			} 
			// only return true if the word is also at the end
			return crawl->is_end;
		}

		bool startsWith(string prefix) {
			Node* crawl = root;
			for (char ch : prefix){
				int ch_idx = char_index(ch);

				if (!crawl->children[ch_idx])
					return false;
				crawl = crawl->children[ch_idx];
			}
			return true;
		}
};

void print_trie(Node* node){
	for (int i = 0; i < 26; i++){
		if (node->children[i]){
			printf("%c\n", i + 'a');
			print_trie(node->children[i]);
		}
	}
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
	Trie* obj = new Trie();
	obj->insert("ab");
	obj->insert("abc");
	cout << obj->startsWith("abc") << endl;
	// print_trie(obj->root);
}
