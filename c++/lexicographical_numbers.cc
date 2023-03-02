#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* children[10]; // 0-9
	bool is_end;

	Node(): is_end(false) {
		for (int i = 0; i < 10; i++)
			children[i] = nullptr;
	}
};

class Trie {
public:
	Node* root;
	Trie(): root(new Node()){}

	void insert(int num){
		string num_str = to_string(num);
		function <void(Node*,string,int)> insertUtil;
		insertUtil = [&](Node* node, string num, int i) -> void {
			if (i == num.size()){
				node->is_end = true;
				return;
			}
			char chidx = num[i] - '0';
			if (!node->children[chidx])
				node->children[chidx] = new Node();
			insertUtil(node->children[chidx], num, i+1);
		};
		
		insertUtil(root, num_str, 0);
	}

	void dfs(Node* node, vector<int>& v, string s=""){
		if (!s.empty())
			v.push_back(stoi(s));
		for (int i = 0; i < 10; i++)
			if (node->children[i])
				dfs(node->children[i], v, s + (char)(i+'0'));
	}

};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
		vector<int> res;        
		for (int i = 1; i <= n; i++)
			trie.insert(i);	
		trie.dfs(trie.root, res);
		return res;
    }
private:
	Trie trie;
};

int main(){
    Solution sol;
	vector<int> res = sol.lexicalOrder(13);
	for (int num : res)
		cout << num << " ";
	cout << "\n";
}
