#include <iostream>
#include <cstring>
using namespace std;

int n, m;
const int MAXN = 7, MAXM = 7;
bool clean_bool[MAXN][MAXM];

/// BLU = true, RED = false

long long int solve(bool _blu[MAXN][MAXM], bool is_current_blu, int current_row, int current_column) {
	///cout << current_row << " " << current_column << endl; 

	if(current_column >= m) {
		current_column = 0;
		++current_row;
	}
	if(current_row >= n) {
		cout << "Overflown Rows" << endl;
		return 0;
	}

	bool blu[MAXN][MAXM];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			blu[i][j] = _blu[i][j];

	blu[current_row][current_column] = is_current_blu;

	if(current_column == m - 1 && current_row == n - 1) {
		//cout << "Potential table:" << endl;
		int num_blus_in_row[MAXN], num_blus_in_col[MAXM];
		memset(num_blus_in_row, 0, sizeof(num_blus_in_row));
		memset(num_blus_in_col, 0, sizeof(num_blus_in_col));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				//cout << blu[i][j] << " ";
				if(blu[i][j]) {
					num_blus_in_row[i]++;
					num_blus_in_col[j]++;
				}
			}
			//cout << endl;
		}

		bool is_viable = true;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(blu[i][j]) {
					if(!(num_blus_in_row[i] > 1 || num_blus_in_col[j] > 1))
						is_viable = false;
				}
				else {
					if(!(m - num_blus_in_row[i] > 1 || n - num_blus_in_col[j] > 1))
						is_viable = false;
				}
		/*if(is_viable)
			cout << "Yezzir! ";
		else
			cout << "Nope... ";

		for(int i = 0; i < n; ++i)
			cout << num_blus_in_row[i] << " ";

		for(int i = 0; i < m; ++i)
			cout << num_blus_in_col[i] << " ";
		
		cout << endl;*/

		if(is_viable)
			return 1;
		return 0;
	}

	return solve(blu, true, current_row, current_column + 1) + solve(blu, false, current_row, current_column + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	/*cin >> n >> m;
	cout << solve(clean_bool, false, 0, 0) + solve(clean_bool, true, 0, 0) << endl;*/
	/*int _n, _m;
	cin >> _n >> _m;
	for(int i = 1; i <= _n; ++i) {
		for(int j = 1; j <= _m; ++j) {*/
			/*n = i;
			m = j;*/
			n = 6;
			m = 7;
			cout << "ans[make_pair(" << i << ", " << j << ")] = " <<
					(solve(clean_bool, false, 0, 0) + solve(clean_bool, true, 0, 0)) % 1000000007 << ";" << endl;
		/*}
	}*/

	return 0;
}