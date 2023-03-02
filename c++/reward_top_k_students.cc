#include <bits/stdc++.h>
using namespace std;

struct Student {
	int id, score;
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
		const int N = report.size();
		vector<int> points(N, 0);
		vector<Student> students;
		for (int i = 0; i < N; i++){
			string rep = report[i];
			stringstream ss(rep);
			string word;
			while (ss >> word){
				if (find(positive_feedback.begin(), positive_feedback.end(), word) != positive_feedback.end())
					points[i]++;
				else if (find(negative_feedback.begin(), negative_feedback.end(), word) != negative_feedback.end())
					points[i]--;
			}
			students.push_back({student_id[i], points[i]});
		}
		sort(students.begin(), students.end(), [](Student a, Student b){
			if (a.score == b.score){
				return a.id < b.id;
			} 
			return a.score > b.score;
		});
		vector<int> res;
		int ki = 0;
		for(Student student : students){
			if (ki == k)
				break;
			res.push_back(student.id);
			cout << student.id << " " << student.score << "\n";
		}
		return res;	
    }
};

int main(){
    Solution sol;
	vector<string> positive_feedback = {"smart","brilliant","studious"}, negative_feedback = {"not"}, report = {"this student is studious","the student is smart"};
	vector<int> student_id = {1,2};
	int k = 2;

	vector<int> res = sol.topStudents(positive_feedback, negative_feedback, report, student_id, k);
	for (int num : res){
		cout << num << " ";
	}
	cout << endl;
}
