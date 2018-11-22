#include <iostream>
using namespace std;

int n;
const int MAXN = 200200;///200 000
long long int dt[3][MAXN];
const int MOD = 1000000007;///1 000 000 007

int main() {
	cin >> n;
	///Iterative DP
	dt[0][1] = 1;
    dt[1][1] = 1;
    dt[2][1] = 1;

    for(int i = 2;i <= n; ++i) {
		dt[0][i] = dt[0][i - 1] + i;
		dt[0][i] %= MOD;
    }

    for(int i = 2;i <= n; ++i) {
		dt[1][i] = dt[1][i - 1] + i * dt[0][i];
		dt[1][i] %= MOD;
    }

    for(int i = 2;i <= n; ++i) {
		dt[2][i] = dt[2][i - 1] + i * dt[1][i];
		dt[2][i] %= MOD;
    }

    cout << dt[2][n] << endl;

	return 0;
}
