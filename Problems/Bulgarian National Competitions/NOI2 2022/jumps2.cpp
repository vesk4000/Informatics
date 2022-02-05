#include <iostream>
using namespace std;

int n, m, a, b, k;
const int MAXNMABK = 10000;

const long long int MOD = 1e9 + 7;

long long int dp[MAXNMABK + 1][MAXNMABK + 1];

long long int solve_brute_force(int sum, int max_add) {
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

long long int solve_smort(int sum, int max_add) {
	for(int i = 0; i <= k; ++i) {
		for(int j = 0; j <= sum; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j <= sum; ++j) {
			if(j <= max_add) {
				if(j == 0) {
					dp[i + 1][j] = 1;
				}
				else {
					dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]);
				}
			}
			else {
				dp[i + 1][j] = (dp[i + 1][j - 1] - dp[i][j - (max_add + 1)] + dp[i][j]);
			}
		}

		/*for(int j = 0; j <= sum; ++j) {
			cout << dp[i][j] << " ";
		}

		cout << endl;*/
	}

	/*for(int j = 0; j <= sum; ++j) {
		cout << dp[k][j] << " ";
	}

	cout << endl;*/

	return dp[k][sum] % MOD;
}

int main() {
	/*cin >> n >> m >> a >> b >> k;
	cout << (solve(n, a) * solve(m, b)) % MOD << endl;*/
	for(int i = 1; i <= 50; ++i) {
		for(int j = 1; j <= 50; ++j) {
			for(k = 1; k <= 50; ++k) {
				long long int solve1 = solve_brute_force(i, j);
				long long int solve2 = solve_smort(i, j);
				cout << i << " " << j << " " << k << endl;
				if(solve1 != solve2) {
					cout << "Incorrect!" << endl;
					cout << "solve1: " << solve1 << endl;
					cout << "solve2: " << solve2 << endl;
					return 0;
				}
			}
		}
	}
}

/*
3 1 2 3 2
*/

/*
100 100 30 30 10
*/