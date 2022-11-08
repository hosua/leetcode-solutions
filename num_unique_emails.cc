#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
		set<string> freq_set;
 		for (string &s : emails){
			normalizeEmail(s);		
			freq_set.insert(s);
		}       
		return freq_set.size();
    }

	void normalizeEmail(string& email){ 
		int idx_at = email.find('@');
		string local = email.substr(0, idx_at);
		string domain = email.substr(idx_at);
		local.erase(remove(local.begin(), local.end(), '.'), local.end());
		email = local + domain;

		int idx_plus = email.find('+');
		idx_at = email.find('@');
		local = local.substr(0, idx_plus);
		email = local + domain;
	}
};
int main(){
	Solution sol;
	vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
	// vector<string> emails = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
	cout << sol.numUniqueEmails(emails);
	
}
