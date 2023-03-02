#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        string out;
        map<char, int> freq_map;
        for (char ch : s){
            if (freq_map.find(ch) == freq_map.end())
                freq_map.insert({ch ,1});
            else    
                freq_map[ch]++;
        }

        vector<pair<char, int>> vec(freq_map.begin(), freq_map.end());
        int x = *max_element(freq_map.begin(), freq_map.end(), )->second;
        sort(vec.begin(), vec.end(), [](const pair<char,int> &left, const pair<char,int> &right){
            return left.second > right.second;
        });

        for (pair<char,int> p : vec){
            for (int i = 0; i < p.second; i++)
                out += p.first;
        }
        return out;
    }
};

int main(){
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s);
}