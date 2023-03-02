#include <bits/stdc++.h>

using namespace std;
// UNFINISHED
/* https://leetcode.com/problems/prefix-and-suffix-search/
 * Design a special dictionary that searches the words in it by a prefix and a suffix.
 *
 * Implement the WordFilter class:
 *
 * WordFilter(string[] words) Initializes the object with the words in the dictionary.
 * f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 * 
 * 
 * Example 1:
 * 
 * Input
 * ["WordFilter", "f"]
 * [[["apple"]], ["a", "e"]]
 * Output
 * [null, 0]
 * Explanation
 * WordFilter wordFilter = new WordFilter(["apple"]);
 * wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".
 */
#define NUM_ALPHA 26
struct Node {
	Node* children[NUM_ALPHA];
	int word_index; // if the end of the word, this var will be set to the index of the word in the list
	bool is_end;
	Node(){
		word_index = -1;
		is_end = false;
		for (int i = 0; i < NUM_ALPHA; i++)
			children[i] = nullptr;
	}
};

class Trie {
public:
	Node* root;
	Trie() : root(new Node()) {}
	void addWord(string word, int word_idx){
		Node* crawl = root;
		for (char ch : word){
			int ch_idx = ch - 'a';
			if (!crawl->children[ch_idx])
				crawl->children[ch_idx] = new Node();

			crawl = crawl->children[ch_idx];
		}
		crawl->word_index = word_idx;
		crawl->is_end = true;
	}
};

class WordFilter {
private:
	int res;
	int pref_len;
	int suff_len;
	Trie* trie;
public:
    WordFilter(vector<string>& words) {
		res = -1;
		pref_len = -1;
		suff_len = -1;
       	// Build trie 
		trie = new Trie();
		for (int i = 0; i < words.size(); i++)
			trie->addWord(words[i], i);
    }
    
    int f(string pref, string suff) {
		Node* pref_end = getPrefEnd(pref);	
		if (!pref_end)
			return -1;
		cout << "found prefix" << endl;
		pref_len = pref.size();
		suff_len = suff.size();
		// Starting from the address of the prefix end, record the max lengths of words that end with the suffix
		searchSuff(pref_end, suff);
       	return res; 
    }
	// searches for the suffix from the prefix end 
	void searchSuff(Node* node, string suff, int mid_len = 0){
		int ch_idx = suff[0] - 'a';
		if (node->children[ch_idx]){
			int res = checkSuff(node, suff);
			int word_len = (pref_len + mid_len + suff_len);
			// cout << word_len << " " << suff_len << endl;
			// cout << res << endl;
			// if ((word_len > max_len) && res != -1){
			// 	cout << pref_len << " " << mid_len << " " << suff_len << endl;
			// 	cout << "setting max len to " << word_len << endl;
			// 	res = res;
			// 	max_len = word_len;
			// }
		}

		for (int i = 0; i < NUM_ALPHA; i++){
			if (node->children[i]){
				searchSuff(node->children[i], suff, mid_len+1);
			}
		}
	}

	// Checks all nodes from a potentional matching word, returns the index of the word if valid word found
	int checkSuff(Node* node, string suff){
		int ch_idx = suff[0] - 'a';	
		if (node->is_end){
			cout << "found word index: " << node->word_index << endl;
			if (res < node->word_index)
				res = node->word_index;
			return node->word_index;	
		}
		if (node->children[ch_idx]){
			if (suff.size())
				return checkSuff(node->children[ch_idx], suff.substr(1));
			else 
				return checkSuff(node->children[ch_idx], suff);
		}
		return -1;
	}
	// get the pointer to the prefix end	
	Node* getPrefEnd(string pref){
		Node* crawl = trie->root;
		for (char ch : pref){
			int ch_idx = ch - 'a';	
			if (!crawl->children[ch_idx])
				return nullptr;
			crawl = crawl->children[ch_idx];
		}
		return crawl;
	}
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

int main(){
	// vector<string> words = { "abbba", "abba" };
	vector<string> words = {"c","c","c","i","c","c","c","c","c","i","c","c","c","c","c","i","c","i","c","c","c","c","c","c","c","i","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","c","i","c","c","c","c","c","c","c","c","c","c","c","c","c"};
	WordFilter sol(words);
	cout << sol.f("c","c");
}
