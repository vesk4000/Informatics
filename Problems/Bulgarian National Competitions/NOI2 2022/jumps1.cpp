#include <iostream>
using namespace std;

int n, m, a, b, k;
const int MAXNMABK = 10000;

const long long int MOD = 1e9 + 7;

long long int dp[2][MAXNMABK + 1];

long long int solve(int sum, int max_add) {
	for(int i = 0; i <= 1; ++i) {
		for(int j = 0; j <= sum; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;


	int oldi = 0;
	int newi = 1;

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j <= sum; ++j) {
			if(j <= max_add) {
				if(j == 0) {
					dp[newi][j] = 1;
				}
				else {
					dp[newi][j] = (dp[newi][j - 1] + dp[oldi][j]) % MOD;
				}
			}
			else {
				dp[newi][j] = (dp[newi][j - 1] - dp[oldi][j - (max_add + 1)] + dp[oldi][j]) % MOD;
			}
		}

		/*for(int j = 0; j <= sum; ++j) {
			cout << dp[i][j] << " ";
		}

		cout << endl;*/
		swap(oldi, newi);
	}

	/*for(int j = 0; j <= sum; ++j) {
		cout << dp[k][j] << " ";
	}

	cout << endl;*/

	dp[oldi][sum] = dp[oldi][sum] % MOD;
	if(dp[oldi][sum] < 0)
		dp[oldi][sum] += MOD;
	return dp[oldi][sum] % MOD;
}

int main() {
	cin >> n >> m >> a >> b >> k;
	long long int solve1 = solve(n, a);
	long long int solve2 = solve(m, b);
	//cout << solve1 << " " << solve2 << endl;
	cout << (solve1 * solve2) % MOD << endl;

	/*k = 50;
	cout << solve(24, 4) << endl;*/
}

/*
3 1 2 3 2
*/

/*
100 100 30 30 10
*/