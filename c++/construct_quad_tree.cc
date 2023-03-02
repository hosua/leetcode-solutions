#include <bits/stdc++.h>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
	vector<vector<int>> grid;
	int N;
public:
	Node* construct(vector<vector<int>>& _grid) {
		N = _grid.size();
		grid = _grid;
		// Helper function
		function <Node*(int,int,int,int)> constructUtil;
		constructUtil = [&](int sx, int ex, int sy, int ey) -> Node* {
			if (sx > ex || sy > ey)
				return nullptr;
			bool is_leaf = true;
			int v = grid[sy][sx]; 
			// Every subsequent value in this quadrant should match v for it to be a leaf
			for (int y = sy; y <= ey; y++){
				for (int x = sx; x <= ex; x++)
					if (grid[y][x] != v){
						is_leaf = false;
						break;
					}
				if (!is_leaf)
					break;
			}
			// If we do have a leaf, then there is no need to recurse further. 
			if (is_leaf)
				return new Node(v == 1, 1);
			// Otherwise, recurse for each sub-quadrant in the current quadrant
			int x_mid = (sx + ex)/2;
			int y_mid = (sy + ey)/2;
			Node *tl, *tr, *bl, *br;
			tl = constructUtil(sx, x_mid, sy, y_mid);
			tr = constructUtil(x_mid+1, ex, sy, y_mid);
			bl = constructUtil(sx, x_mid, y_mid+1, ey);
			br = constructUtil(x_mid+1, ex, y_mid+1, ey);
			return new Node(0,0,tl,tr,bl,br);
		};
    	return constructUtil(0, N-1, 0, N-1);
    }
};

void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	while (!q.empty()){
		size_t breadth = q.size();
		while (breadth--){
			Node* node = q.front(); q.pop();
			if (!node)
				continue;
			cout << node->val << " ";
			q.push(node->topLeft);
			q.push(node->topRight);
			q.push(node->bottomLeft);
			q.push(node->bottomRight);
		}
		cout << "\n";
	}
}

int main(){
    Solution sol;
	vector<vector<int>> mat = {{0,1},{1,0}};
	// vector<vector<int>> mat = {{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
	Node* res = sol.construct(mat);
	levelOrder(res);

}
