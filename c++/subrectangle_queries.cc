#include <bits/stdc++.h>
using namespace std;

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rect): _rect(rect){}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int new_val) {
       	for (int y = row1; y <= row2; y++)
			for (int x = col1; x <= col2; x++)
				_rect[y][x] = new_val;
    }
    
    int getValue(int row, int col) {
       	return _rect[row][col]; 
    }
private:
	vector<vector<int>> _rect;
};


int main(){
	int res;
	vector<vector<int>> rect = {{1,2,1},{4,3,4},{3,2,1},{1,1,1}};
	SubrectangleQueries sq(rect);
	res = sq.getValue(0, 2); // 1
	cout << res << "\n";
	sq.updateSubrectangle(0,0,3,2,5);
	res = sq.getValue(0, 2); // 5
	cout << res << "\n";
}
