#include <iostream>
using namespace std;

int n, m, a, b, k;
const int MAXNMABK = 10000;

const long long int MOD = 1e9 + 7;

long long int dp[MAXNMABK + 1][MAXNMABK + 1];

long long int solve(int sum, int max_add) {
	for(int i = 0; i <= k; ++i) {
		for(int j = 0; j <= sum; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j <= sum; ++j) {
			for(int add = 0; add <= max_add; ++add) {
				if(j + add <= sum) {
					dp[i + 1][j + add] = (dp[i + 1][j + add] + dp[i][j]) % MOD;
				}
			}
		}
	}

	return dp[k][sum];
}

int main() {
	cin >> n >> m >> a >> b >> k;
	cout << (solve(n, a) * solve(m, b)) % MOD << endl;
}

/*
3 1 2 3 2
*/

/*
100 100 30 30 10
*/