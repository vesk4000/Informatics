#include <iostream>
#include <string>

using namespace std;

struct coordinates {
	int x;
	int y;
};

struct mv {
	coordinates a;
	coordinates b;
};

mv mvs[2048];

int main() {
	int t = 0;
	cin >> t;
	for(int tt = 0; tt < t; ++tt) {
		string s;
		int n;
		cin >> n;
		cin >> s;
		for(int i = 0;i < s.size(); ++i) {

			if(s[i] == 'E')
				s[i] = 'S';
			else
				s[i] = 'E';

		}
		cout << "Case #" << tt + 1 << ": " << s << endl;
	}
	return 0;
}

