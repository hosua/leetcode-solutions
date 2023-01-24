#include <bits/stdc++.h>
using namespace std;

class Union {
private:
	vector<int> rep;
	vector<int> sizes;
	int R;
public:
	Union(size_t sz){
		R = sz;
		rep.resize(R);
		sizes.resize(R, 1);

		// set rep roots to themselves
		for (int i = 0; i < sz; i++)
			rep[i] = i;
	}

	int find(int x){
		assert(x >= 0 and "Find index was below 0\n");
		// if the representative = current node, then we have the root of the set
		if (rep[x] == x)
			return x;
		// recursively search the path and check the next node
		return rep[x] = find(rep[x]);
	}

	void unionize(int x, int y){
		int x_rt = find(x);
		int y_rt = find(y);


		// only perform if not already in the same group
		if (x_rt != y_rt){
			// merge smaller set to larger set
			if (sizes[x_rt] < sizes[y_rt]){
				sizes[y_rt] += sizes[x_rt]; // add smaller set size to larger set size
				rep[x_rt] = y_rt; // set root of smaller set to larger set root
			} else {
				sizes[x_rt] += sizes[y_rt]; // add smaller set size to larger set size
				rep[y_rt] = x_rt; // set root of smaller set to larger set root
			}
		}
	}

	void printRep(){
		for (int i = 0; i < R; i++){
			char ch = i + 'a';
			cout << ch << "(" << rep[i] << ")\n";
		}
	}

	void printSizes(){
		for (int i = 0; i < R; i++){
			cout << sizes[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	string s = "aecd";
	string t = "efgh";

	Union u(26);

	for (int i = 0; i < s.size(); i++){
		int a = s[i]-'a', b = t[i]-'a';
		u.unionize(a,b);
	}
	
	u.printRep();
	for (char ch : t){
		int r = u.find(ch-'a');
		cout << r << endl;
	}

	// u.unionize('a'-'a','b'-'a');
	for (char ch : t){
		int r = u.find(ch-'a');
		cout << r << endl;
	}

	u.printSizes();
}

