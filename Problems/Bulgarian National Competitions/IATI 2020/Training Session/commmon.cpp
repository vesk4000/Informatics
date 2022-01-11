#include <iostream>
#include <set>
using namespace std;

int k;
set<int> s;

int main() {
	cin >> k;
	int n[1024];
	for(int i = 0; i < k; ++i) {
		cin >> n[i];
	}
	int num;
	for(int i = 0; i < n[0]; ++i) {
		cin >> num;
		s.insert(num);
	}
	for(int i = 1; i < k; ++i) {
		set<int> new_set;
		for(int j = 0; j < n[i]; ++j) {
			cin >> num;
			if(s.find(num) != s.end())
				new_set.insert(num);
		}
		s = new_set;
	}
	cout << *s.begin() << endl;
	return 0;
}