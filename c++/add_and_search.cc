#include <bits/stdc++.h>

using namespace std;
#define ALPHA_SIZE 26
class Node {
	public:
		Node(){
			is_end = false;
			for (int i = 0; i < ALPHA_SIZE; i++){
				children[i] = NULL;
			}
		}
		Node* children[ALPHA_SIZE];
		bool is_end;
};

class WordDictionary {
	private:
		Node* root;

		void search_helper(Node* node, string word, bool &found_match, int idx=0){
			if (idx == word.size() && node->is_end){
				cout << "found match!" << endl;
				found_match = true;
				return;
			}
			char curr_ch = word[idx];	
			// cout << curr_ch << '\t' << idx << '\t' << word.size() << '\t' << node->is_end << endl;
			// cout << curr_ch << ' ';
			// match any
			if (curr_ch == '.'){
				// check all children

				for (int i = 0; i < ALPHA_SIZE; i++){
					if (node->children[i]){
						search_helper(node->children[i], word, found_match, idx+1);
						// cout << endl;
						if (found_match)
							return;
					}	
				}	
			} else { // match specific
				int ch_idx = curr_ch - 'a';
				if (ch_idx < 0 || ch_idx > ALPHA_SIZE-1){
                    found_match = false;
                    return;
                }

				if (!node->children[ch_idx]){
					found_match = false;
					return;
				} 
				search_helper(node->children[ch_idx], word, found_match, idx+1);
			}
		}

	public:
		WordDictionary() {
			root = new Node(); 
		}

		void addWord(string word) {
			Node* crawl = root;
			for (char ch : word){
				int ch_idx = tolower(ch) - 'a';	
				if (!crawl->children[ch_idx]){
					crawl->children[ch_idx] = new Node();
				} 
				crawl = crawl->children[ch_idx];
			} 
			crawl->is_end = true;
		}

		bool search(string word) {
			bool found_match = false;
			search_helper(root, word, found_match);
			return found_match;
		}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
	WordDictionary* dict = new WordDictionary();
	dict->addWord("at");
	dict->addWord("an");
	dict->addWord("add");
	dict->addWord("a");
	bool res = dict->search("a.d");
	cout << res << endl;
}
