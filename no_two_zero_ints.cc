#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
		int a = n-1;
		int b = 1;

		string as = to_string(a);
		string bs = to_string(b);
		while (as.find('0') != string::npos or
				bs.find('0') != string::npos){
			a--;
			b++;
			as = to_string(a);
			bs = to_string(b);
		}
		return {a,b};
    }
};
