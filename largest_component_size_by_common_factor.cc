#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
	if (b == 0)
		return a;
	
	return GCD(b, a % b);
}

class Union {
private:
	size_t max_size, N;
	vector<int> vals, sizes, rep;
public:
	Union(vector<int> nums){
		max_size = 1;
		vals = nums;
		this->N = nums.size();
		sizes.resize(N, 1); 
		rep.resize(N);
		for (int i = 0; i < N; i++)
			rep[i] = i;
	}
	
	size_t getMaxSize(){
		return max_size;
	}

	int find(int x){
		if (rep[x] == x)
			return x;
		return rep[x] = find(rep[x]);
	}

	void unionize(int x, int y){
		int xrt = find(x), yrt = find(y);
		// only unionize if roots are not equal
		if (xrt != yrt){		
			// preserve smaller root as the root of the merged set
			if (xrt < yrt){
				sizes[xrt] += sizes[yrt];
				if (sizes[xrt] > max_size)
					max_size = sizes[xrt];
				rep[yrt] = xrt;
			} else {
				sizes[yrt] += sizes[xrt];
				if (sizes[yrt] > max_size)
					max_size = sizes[yrt];
				rep[xrt] = yrt;
			}
		}
	}

	void printReps(){
		for (int i = 0; i < N; i++){
			int rt = find(rep[i]);
			int rtv = vals[rt];
			cout << rt << "(" << rtv << ")\n";
		}
	}

	void printSizes(){
		for (int sz : sizes){
			cout << sz << " ";
		}
		cout << endl;
	}
};

class Solution {
private:
public:
    int largestComponentSize(vector<int>& nums) {
		const int N = nums.size();
		Union u(nums);
		
		// TLE
		for (int i = 0; i < N; i++){
			int a = nums[i];
			for (int j = 0; j < N; j++){
				if (i != j){
					int b = nums[j];	
					int common_factor = GCD(a,b);
					if (common_factor != 1)
						u.unionize(i,j);
				}
			}
		}

		// u.printReps();	
		// u.printSizes();
		return u.getMaxSize();
    }
};

int main(){
	Solution sol;
	// vector<int> nums = {4,6,15,35}; // 4
	vector<int> nums = {20,50,9,63}; // 2
	int res = sol.largestComponentSize(nums);
	cout << res << endl;
	//

}
