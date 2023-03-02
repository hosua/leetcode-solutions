#include <bits/stdc++.h>
using namespace std;


// TODO I'm too sleep deprived. Do this tomorrow, it should be easy.
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, 
			vector<vector<string>>& ingredients, vector<string>& supplies) {
    }

};

int main(){
    Solution sol;
	vector<string> recipes = {"bread","sandwich"}, supplies = {"yeast","flour","meat"};
	vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"}};
	vector<string> res = sol.findAllRecipes(recipes, ingredients, supplies);
	for (string s : res)
		cout << s << " ";
	cout << "\n";
}
