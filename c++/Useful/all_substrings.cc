// C++ program to print all possible
// substrings of a given string

#include<bits/stdc++.h>
using namespace std;

vector<string> subStrings(string str){
	vector<string> substrings;
	const int N = str.size();
	for (int len = 1; len <= N; len++){ // pick start
		for (int i = 0; i <= N-len; i++){ // pick end
			int j = i+len-1;
			string s;
			for (int k = i; k <= j; k++)
				s += str[k];
			substrings.push_back(s);
		}
	}
	return substrings;
}

// Driver program to test above function
int main()
{
	char str[] = "abc";
	vector<string> res = subStrings(str);
	for (string s : res){
		cout << s << endl;
	}
	return 0;
}

