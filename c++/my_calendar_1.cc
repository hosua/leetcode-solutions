#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
private:
	vector<pair<int,int>> v;
	// ret true if a overlaps b
	bool rangeOverlaps(pair<int,int> a, pair<int,int> b){
		int s1 = a.first, e1 = a.second;
		int s2 = b.first, e2 = b.second;
		return (s1 < e2) and (s2 < e1);
	}
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
		pair<int,int> a = {start,end};
		for (pair<int,int> p : v){
			pair<int,int> b = p;
			if (rangeOverlaps(a,b))
				return false;
		}
		v.push_back(a);
		return true;
    }
};
int main(){
    MyCalendar cal;
	vector<pair<int,int>> v = {{47,50},{33,41},{39,45},{33,42},{25,32},{26,35},{19,25},{3,8},{8,13},{18,27}};

	// [null,true,true,false,false,true,false,true,true,true,false]
	for (pair<int,int> p : v){
		cout << cal.book(p.first, p.second) << "\n";
	}
}
