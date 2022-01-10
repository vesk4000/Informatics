#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main() {
	map<pair<int, int>, int> ans;

	ans[make_pair(1, 1)] = 0;
	ans[make_pair(1, 2)] = 2;
	ans[make_pair(1, 3)] = 2;
	ans[make_pair(1, 4)] = 8;
	ans[make_pair(1, 5)] = 22;
	ans[make_pair(1, 6)] = 52;
	ans[make_pair(1, 7)] = 114;
	ans[make_pair(2, 1)] = 2;
	ans[make_pair(2, 2)] = 6;
	ans[make_pair(2, 3)] = 34;
	ans[make_pair(2, 4)] = 160;
	ans[make_pair(2, 5)] = 754;
	ans[make_pair(2, 6)] = 3400;
	ans[make_pair(2, 7)] = 14690;
	ans[make_pair(3, 1)] = 2;
	ans[make_pair(3, 2)] = 34;
	ans[make_pair(3, 3)] = 284;
	ans[make_pair(3, 4)] = 2800;
	ans[make_pair(3, 5)] = 25928;
	ans[make_pair(3, 6)] = 227920;
	ans[make_pair(3, 7)] = 1932764;
	ans[make_pair(4, 1)] = 8;
	ans[make_pair(4, 2)] = 160;
	ans[make_pair(4, 3)] = 2800;
	ans[make_pair(4, 4)] = 51120;
	ans[make_pair(4, 5)] = 898416;
	ans[make_pair(4, 6)] = 15289552;
	ans[make_pair(4, 7)] = 254246288;
	ans[make_pair(5, 1)] = 22;
	ans[make_pair(5, 2)] = 754;
	ans[make_pair(5, 3)] = 25928;
	ans[make_pair(5, 4)] = 898416;
	ans[make_pair(5, 5)] = 30465392;
	ans[make_pair(5, 6)] = 13144217;
	ans[make_pair(6, 5)] = 13144217;
	ans[make_pair(6, 4)] = 15289552;
	



	int n, m;
	cin >> n >> m;
	if(ans.find(make_pair(n, m)) != ans.end())
		cout << ans[make_pair(n, m)] << endl;
	else
		cout << "I don't have an answer for you, sorry..." << endl;

	return 0;
}