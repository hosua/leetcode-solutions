#include <bits/stdc++.h>
using namespace std;

#define ALPHA 26 

class Union {
private:
	vector<int> rep;
public:

	Union(){
		rep.resize(ALPHA);
		for (int i = 0; i < ALPHA; i++) // set each element to its index to indicate a root
			rep[i] = i;	
	}

	int find(int x){
		if (rep[x] == x) // found the root
			return x;
		return rep[x] = find(rep[x]); // recursively call find and compress the path of each child
	}

	void unionize(int x, int y){
		// find the roots of x and y 
		int xrt = find(x);
		int yrt = find(y);
		
		// only perform merge if x and y are not already in the same set
		if (xrt != yrt){
			// merge the set with the higher lexicographical order to the set with the lower lexicographical order
			// in order to preserve the smaller root as the representative
			if (xrt-'a' > yrt-'a'){ // xrt is higher 
				rep[xrt] = yrt; // set root of x to the root of y
			} else { // yrt is higher
				rep[yrt] = xrt; // set root of y to the root of x
			}
		}
	}
	
	void printReps(){
		for (int i = 0; i < ALPHA; i++){
			char ch = i+'a';	
			char rt = rep[i]+'a';
			cout << ch << "(" << rt << ")\n";
		}
	}
};

class Solution {
private:
	Union u;
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
		string res;
		const int N = s1.size();
		for (int i = 0; i < N; i++){
			int a = s1[i]-'a', b = s2[i]-'a';
			u.unionize(a,b);
		}

		for (int i = 0; i < baseStr.size(); i++){
			int ci = baseStr[i]-'a';
			res +=  u.find(ci)+'a'; // find, compress paths, and get the resulting string
		}
		return res;
    }
};

int main(){
	Solution sol;
	// string s1 = "parker", s2 = "morris", baseStr = "parser"; // "makkek"
	// string s1 = "hello", s2 = "world", baseStr = "hold";
	string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"; // "aauaaaaada"
	
	string res = sol.smallestEquivalentString(s1, s2, baseStr);
	cout << res << endl;
}
