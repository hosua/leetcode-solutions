#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int num_rows) {
		if (num_rows == 1)
			return s;
		string res;
		vector<string> mat(num_rows, "");

		downstate(0, 0, num_rows, s, mat);
		
		for (string e : mat)
			for (char ch : e )
				res.push_back(ch);

		return res;
    }

private:
	void downstate(int i, int row, const size_t num_rows, string input, vector<string>& mat){
		if (i == input.size())
			return;

		char ch = input[i];
		mat[row].push_back(ch);
		
		if (row == num_rows-1)
			upstate(i+1, row-1, num_rows, input, mat);
		else
			downstate(i+1, row+1, num_rows, input, mat);
	}

	void upstate(int i, int row, const size_t num_rows, string input, vector<string>& mat){
		if (i == input.size())
			return;
		
		char ch = input[i];
		mat[row].push_back(ch);

		if (row == 0)
			downstate(i+1, row+1, num_rows, input, mat);
		else
			upstate(i+1, row-1, num_rows, input, mat);
	}
};

int main(){
    Solution sol;
	// string s = "PAYPALISHIRING";
	// int num_rows = 3;
	string s = "ABAB";
	int num_rows = 1;
	string res = sol.convert(s, num_rows);
	cout << res << "\n";
}
