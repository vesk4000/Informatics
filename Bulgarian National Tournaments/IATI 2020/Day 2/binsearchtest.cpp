#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;

bool sort_by_x_cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n, w, h;
	cin >> n >> w >> h;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end(), sort_by_x_cmp);

	for(int i = 0; i < n; ++i) {
		cout << vec[i].first << " " << vec[i].second << " -> " << endl;;

		int orx = vec[i].first - w;

		int l = 0, r = i;
		while(true) {
			cout << l << " " << r << endl;
			if(l >= r)
				break;
			if(l == r - 1)
				if(vec[l].first >= orx)
					break;
				else {
					l = r;
					break;
				}
			int mid = (r - l) / 2 + l;
			if(vec[mid].first < orx)
				l = mid;
			else
				r = mid;
		}

		cout << "Left-most in the triangle is " << vec[l].first << " " << vec[l].second << endl;
	}

	return 0;
}
