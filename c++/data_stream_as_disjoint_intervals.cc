#include <bits/stdc++.h>
using namespace std;

class SummaryRanges {
private:
	vector<vector<int>> res;
	set<vector<int>> sv; // set vector of intervals
public:
    SummaryRanges() {
        
    }

	bool cmp = [](int a, vector<int> b){ return a < b[0]; };
    
    void addNum(int value) {
		vector<int> search = {value, 0};
   		if (sv.find(search) == sv.end()){

		}
    }
    
    vector<vector<int>> getIntervals() {

		function <void(int,int,int)> getSetVecs;

		getSetVecs = [&](int target, int left, int right) -> void {
			int mid = (left+right)/2;
			if ( res[mid][0] == target){

			}
		};

		for (int i = 0; i < sv.size(); i++){

		}	
		return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
int main(){
    SummaryRanges sr;

}
