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
    string serialize(TreeNode* node) {
		if (!node)
			return "*";
		string left = serialize(node->left);
		string right = serialize(node->right);
		return "{" + to_string(node->val) + ":[" + left + "," + right + "]}";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		TreeNode* root = deserializeUtil(nullptr, nullptr, data);
		return nullptr;
    }

	TreeNode* deserializeUtil(TreeNode* node, TreeNode* parent, string data, int i=0){
		char ch = data[i];
		switch(ch){
			case '{':
				// down a level
				break;
			case '}':
				// up a level
				break;
			case '*':
				// null
				break;
		}
		if (isdigit(ch)){
				
		}
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
	// TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, new TreeNode(6), new TreeNode(7)));
	// TreeNode* root = nullptr;
	string encoded = codec.serialize(root);
	cout << encoded << endl;
	TreeNode* res = codec.deserialize(encoded);
}
