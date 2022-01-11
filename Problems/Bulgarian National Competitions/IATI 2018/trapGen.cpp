#include <iostream>
using namespace std;

int n;
int ans;

bool usedA[100][100];

int conv(int num) {
	return num + 30;
}

void solve(bool used[100][100], int pM, int x, int y, bool vert) {
	if(pM == n + 1) {
		if(used[conv(x + 1)][conv(y)]
		&& used[conv(x - 1)][conv(y)]
		&& used[conv(x)][conv(y + 1)]
		&& used[conv(x)][conv(y - 1)]) {
			++ans;
		}
		return;
	}
	if(used[conv(x + 1)][conv(y)] == false) {
		used[conv(x + 1)][conv(y)] = true;
		solve(used, pM + 1, x + 1, y, vert);
		used[conv(x + 1)][conv(y)] = false;
	}
	if(used[conv(x - 1)][conv(y)] == false) {
		used[conv(x - 1)][conv(y)] = true;
		solve(used, pM + 1, x - 1, y, vert);
		used[conv(x - 1)][conv(y)] = false;
	}
	if(used[conv(x)][conv(y + 1)] == false) {
		used[conv(x)][conv(y + 1)] = true;
		solve(used, pM + 1, x, y + 1, true);
		used[conv(x)][conv(y + 1)] = false;
	}
	if(used[conv(x)][conv(y - 1)] == false && vert) {
		used[conv(x)][conv(y - 1)] = true;
		solve(used, pM + 1, x, y - 1, true);
		used[conv(x)][conv(y - 1)] = false;
	}
	return;
}

int main() {
	int m1, m2;
	cin >> m1 >> m2;
	for(int i = m1;i <= m2; ++i) {
		ans = 0;
		n = i;
		int x1 = conv(0);
		int y1 = conv(0);
		int x2 = conv(1);
		int y2 = conv(0);
		usedA[x1][y1] = true;
		usedA[x2][y2] = true;
		solve(usedA, 2, 1, 0, false);
		cout << i << " " << ans << endl;
	}
	return 0;
}
