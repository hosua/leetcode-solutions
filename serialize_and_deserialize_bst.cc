#include <bits/stdc++.h>
using namespace std;

// TODO (maybe)
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		if (!root)
			return "";
    	string data;    
		queue<TreeNode*> q;
		q.push(root);
		data += to_string(root->val) + "|";
		while(not q.empty()){
			int breadth = q.size();
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				if (node->left){
					q.push(node->left);
					data += to_string(node->left->val);
				} else {
					data += "N"; // denotes null node
				}

				data += ":"; // : separates left and right nodes
				if (node->right){
					q.push(node->right);
					data += to_string(node->right->val);
				} else {
					data += "N"; // denotes null node
				}
				data += " ";
			}
			data += "|"; // | indicates the next level
		}
		
		return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		const int N = data.size();
		if (N == 0)
			return nullptr;
		int i = 0;
		// get the root
		string num_str;
		while (isdigit(data[i])){
			num_str += data[i];
			i++;
		}
       	TreeNode* root = new TreeNode(stoi(num_str));; 
		TreeNode* cursor = root;
		num_str.clear();
		bool is_left = true;
		while (i < N){
			if (isdigit(data[i])){
				num_str += data[i];
			} else {
				if (is_left){
					cursor->left = new TreeNode(stoi(num_str));	
					is_left = false;
				} else {
					cursor->right = new TreeNode(stoi(num_str));	
					is_left = true;
				}
				num_str.clear();
			}
		}
		return root;
    }
};

int main(){
    Codec codec;
	// Your Codec object will be instantiated and called as such:
	// Codec* ser = new Codec();
	// Codec* deser = new Codec();
	// string tree = ser->serialize(root);
	// TreeNode* ans = deser->deserialize(tree);
	// return ans;
	TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
	// TreeNode* root = nullptr;
	string encoded = codec.serialize(root);
	cout << encoded << endl;
	TreeNode* res = codec.deserialize(encoded);
}
