#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
    	function <void(TreeNode*)> bfs;
		int sum = 0;
		bfs = [&](TreeNode* start) -> void {
			queue<TreeNode*> q;
			q.push(start);
			while (!q.empty()){
				size_t breadth = q.size();
				while (breadth--){
					TreeNode* node = q.front(); q.pop();
					if (!node)
						continue;
					q.push(node->left);
					q.push(node->right);
					// Sum the grandchildren
					if (node->val % 2 == 0)
						sum += sumGrandChildren(node);
				}
			}
		};
		bfs(root);
		return sum;
    }

private:
	int sumGrandChildren(TreeNode* grandparent){
		int res = 0;
		queue<TreeNode*> q;
		q.push(grandparent);
		int level = 0;
		while (!q.empty()){
			size_t breadth = q.size();
			while (breadth--){
				TreeNode* node = q.front(); q.pop();
				if (!node)
					continue;
				q.push(node->left);
				q.push(node->right);
				// Sum the grandchildren
				if (level == 2)
					res += node->val;	
			}
			if (level == 2)
				return res;
			level++;
		}

		return res;
	}
};

int main(){
    Solution sol;
	TreeNode* root = new TreeNode(6, new TreeNode(7, new TreeNode(2, new TreeNode(9), nullptr), new TreeNode(7, new TreeNode(1), new TreeNode(4))), new TreeNode(8, new TreeNode(1), new TreeNode(3, nullptr, new TreeNode(5))));
	int res = sol.sumEvenGrandparent(root);
	cout << res << "\n";
}
