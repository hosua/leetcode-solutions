#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

		function <long long(long long,long long)> binarySearch;
		binarySearch = [&](long long left, long long right) -> long long {
			long long mid = left + (right-left)/2;
			if (left > right){
				return left; // We have our answer
			} else if (checkTime(time, mid, totalTrips)){
				// time threshold was met, our answer may potentially be smaller
				return binarySearch(left, mid-1);
			} else {
				// time threshold was not met, our answer must be greater
				return binarySearch(mid+1, right);
			}
		};

		long long min_time = (long long)*min_element(time.begin(), time.end());
		long long worst_case = min_time*(long long)totalTrips + 0;
		return binarySearch(0, worst_case)+0;
	}

private:

	// Returns true if the time being checked yields enough total trips
	bool checkTime(vector<int> time, long long time_to_check, long long totalTrips){
		long long trips = 0;
		for (int t : time)
			trips += time_to_check/(long long)t;
		return (trips >= totalTrips);
	}

	// Working brute force
    long long minimumTimeBF(vector<int>& time, int totalTrips) {
		const int N = time.size();
		vector<int> trips(N, 0);
		
		long long curr_time = 1;
		while (true){
			long long sum = 0;
			for (int i = 0; i < N; i++){
				if (curr_time % time[i] == 0)
					trips[i]++;	

				sum += (long long)trips[i];
			}

			if (sum >= totalTrips)
				break;
			curr_time++;
		}
		return curr_time;
    }
};

int main(){
    Solution sol;
	// vector<int> time = {1,2,3}; int totalTrips = 5; // 3
	vector<int> time = {10000}; int totalTrips = 10000000; // 100000000000

	long long res = sol.minimumTime(time, totalTrips);
	cout << res << "\n";
}
