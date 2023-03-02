#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE IS TOO SLOW
class StockSpanner {
private:
	stack<int> stocks;
	map<int, int> span_map; // idx, spans
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
		int res = 0;
       	stocks.push(price); 
		stack<int> stocks_copy = stocks;
		int idx = stocks_copy.size()-1;

		int p = stocks_copy.top();

		while (!stocks_copy.empty()){
			int q = stocks_copy.top();
			stocks_copy.pop();
			if (q <= p)
				res++;
			else
				break;
		}
		span_map.insert( {idx, res} );
		return res;
    }
};


int main(){
	StockSpanner sol;
	vector<int> lst = {100,80,60,70,60,75,85};
	// vector<int> lst = {29, 91, 62, 76, 77, 78, 79};
	for (int num : lst){
		cout << sol.next(num) << " ";
	}
}
