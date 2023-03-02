#include <bits/stdc++.h>
using namespace std;
#define ALPHA 26
class Solution {
public:
    int titleToNumber(string columnTitle) {
		int n = 0, p = 0;
 		for (int i = columnTitle.size()-1; i >= 0; i--, p++)
			n += (columnTitle[i]-'A'+1)*pow(ALPHA, p);
		return n;
    }
};
int main(){
	Solution sol;
	cout << sol.titleToNumber("ZY");
	// cout << sol.titleToNumber("AB");
}
