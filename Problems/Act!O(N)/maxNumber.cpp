#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[128];

bool cmp(string a, string b) {
	int sz = min(a.size(), b.size());
	bool eql = true;
	for(int i = 0;i < sz; ++i) {
		if(a[i] < b[i])
			return true;
		if(a[i] > b[i])
			return false;
	}
	if(a.size() < b.size())
		return false;
	return true;
}

int main() {
	cin >> n;
	for(int i = 0;i < n; ++i)
		cin >> s[i];
	/*for(int i = 0;i < n; ++i) {
		for(int j = i + 1;j < n; ++j) {
			//cout << s[i] << " " << s[j] << " " << cmp(s[i], s[j]) << endl;
			if(cmp(s[i], s[j]))
				swap(s[i], s[j]);
		}
	}*/
	sort(s, s + n, cmp);
	reverse(s, s + n);
	/*sort(s, s + n, cmp);
	reverse(s, s + n);*/
	for(int i = 0;i < n; ++i)
		cout << s[i];
	return 0;
}
