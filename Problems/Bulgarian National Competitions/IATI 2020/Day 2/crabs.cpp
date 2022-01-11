#include <iostream>
using namespace std;

int n ,k;
//const int MAXN = 100005;
const int MAXN = 305;
int a[MAXN];
int mem[MAXN][MAXN][MAXN][MAXN];

int solve(int index, int sum_in_tank, int num_in_tank, int num_tanks) {
	if(mem[index][sum_in_tank][num_in_tank][num_tanks] != 0)
		return mem[index][sum_in_tank][num_in_tank][num_tanks];//cout << index << " " << sum_in_tank << " " << num_in_tank << " "  << num_tanks << endl;
	if(index == n)
		return 0;
	if(num_tanks >= k - 1) {
		return mem[index][sum_in_tank][num_in_tank][num_tanks] = solve(index + 1, sum_in_tank + a[index], num_in_tank + 1, num_tanks) + num_in_tank * a[index] + sum_in_tank;
	}
	return mem[index][sum_in_tank][num_in_tank][num_tanks] = min( solve(index + 1, sum_in_tank + a[index], num_in_tank + 1, num_tanks) + num_in_tank * a[index] + sum_in_tank,
				solve(index + 1, a[index], 1, num_tanks + 1) );
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << solve(0, 0, 0, 0) << endl;
	return 0;
}
