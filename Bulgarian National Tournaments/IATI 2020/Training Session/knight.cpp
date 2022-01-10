#include <iostream>
#include <vector>
using namespace std;

int clean_used[4][5];
int ans;

void answer(int used[4][5]) {
	for(int y = 0; y < 4; ++y) {
		for(int x = 0; x < 5; ++x) {
			cout << used[y][x] << " ";
		}
	}
	cout << endl;
	ans++;
}

void check(int ref_used[4][5], int step, int y, int x) {
	if(!(y >= 0 && y <= 3 && x >= 0 && x <= 4))
		return;

	int used[4][5];
	for(int _y = 0; _y < 4; ++_y) {
		for(int _x = 0; _x < 5; ++_x) {
			used[_y][_x] = ref_used[_y][_x];
		}
	}
	if(used[y][x] != 0)
		return;
	used[y][x] = step;
	//answer(used);
	//cout << step << " " << y << " " << x << endl;
	bool flag = false;
	for(int _y = 0; _y < 4; ++_y) {
		for(int _x = 0; _x < 5; ++_x) {
			if(used[_y][_x] == 0) {
				flag = true;
			}
		}
	}
	if(!flag) {
		answer(used);
		return;
	}

	check(used, step + 1, y - 2, x + 1);
	check(used, step + 1, y - 1, x + 2);
	check(used, step + 1, y + 1, x + 2);
	check(used, step + 1, y + 2, x + 1);
	check(used, step + 1, y - 2, x - 1);
	check(used, step + 1, y - 1, x - 2);
	check(used, step + 1, y + 1, x - 2);
	check(used, step + 1, y + 2, x - 1);
}

int main() {

	for(int y = 0; y < 4; ++y) {
		for(int x = 0; x < 5; ++x) {
			check(clean_used, 1, y, x);
			//answer(clean_used);
		}
	}
	cout << ans << endl;
	return 0;
}