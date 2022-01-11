#include <iostream>
#include <string>

using namespace std;

int t;

int main() {
	cin >> t;
	for(int tt = 0; tt < t; ++tt) {
		string s;
		cin >> s;
		string a = "", b = "";
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '4') {
				a += "3";
				b += "1";
			}
			else {
				a += s[i];
				b += "0";
			}
		}
		string b1 = "";
		bool flag = false;
		for(int i = 0; i < b.size(); ++i) {
			if(!flag) {
				if(b[i] == '1')
					flag = true;
			}
			if(flag) {
				b1 += b[i];
			}
		}
		cout << "Case #" << tt + 1 << ": " << a << " " << b1 << endl;
	}
	return 0;
}
