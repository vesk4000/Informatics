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
		int x = 0, y = 0;
		coordinates oldcoords;
		oldcoords.x = 0;
		oldcoords.y = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == 'E') {
				x += 1;
			}
			else {
				y += 1;
			}
			mv mv1;
			coordinates cc;
			cc.x = x;
			cc.y = y;
			mv1.a = oldcoords;
			mv1.b = cc;
			oldcoords = cc;
			mvs[i] = mv1;
		}
		for(int i = 0; i < s.size(); ++i) {
			cout << mvs[i].a.x << " " << mvs[i].a.y << " " << mvs[i].b.x << " " << mvs[i].b.y << endl;
		}
	}
	return 0;
}
