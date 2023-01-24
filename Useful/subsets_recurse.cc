#include <bits/stdc++.h>
using namespace std;

class Foo {
private:
public:
	vector<string> getSubstrings(string str){
		set<string> s;
		vector<string> res;
		function <void(int,string,string)> rec = 
			[&](int i, string subseq, string input) -> void {
			// base case
			if (i == input.size()){
				if (s.find(subseq) == s.end()){
					s.insert(subseq);
					res.push_back(subseq);
				}
				return;
			}
			
			subseq += input[i];
			rec(i+1, subseq, input);
			subseq.pop_back();

			rec(i+1, subseq, input);
		};

		rec(0, "", str);
		return res;
	}
};

int main(){
    Foo bar;
	vector<string> res = bar.getSubstrings("Joshua");
	for (string s : res)
		cout << s << " ";
	cout << "\n";
}
