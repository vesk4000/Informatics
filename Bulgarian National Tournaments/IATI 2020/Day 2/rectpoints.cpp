#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std;

int n;
int w, h;

unordered_set<long long int> hash_points;
vector<pair<int, int>> list_points;

int ans = 0;


bool sort_by_x_cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

const long long int mult = numeric_limits<int>::max();

long long int coords2num(pair<int, int> coords) {
	return coords.first * mult + coords.second;
}

long long int coords2num(int x, int y) {
	return coords2num({x, y});
}

pair<int, int> num2coords(long long int num) {
	return {num / mult, num % mult};
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> w >> h;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		//hash_points.insert(coords2num(x, y));
		list_points.push_back({x, y});
	}

	sort(list_points.begin(), list_points.end(), sort_by_x_cmp);

	for(int i = 0; i < n; ++i) {
		//cout << list_points[i].first << " " << list_points[i].second << endl;
		int orx = list_points[i].first;
		int ory = list_points[i].second;
		int enx = orx - w;
		int eny = ory - h;
		swap(orx, enx);
		swap(ory, eny);
		/// Check if there is a possible rectangle
		/*if( hash_points.find(coords2num(enx, eny)) != hash_points.end()
				&& hash_points.find(coords2num(orx + w, ory)) != hash_points.end()
				&& hash_points.find(coords2num(orx, ory + h)) != hash_points.end()) {*/
			/// Check all points to see if they are within the rectangle
			int num_rect = 0;
			for(int j = 0; j < n; ++j) {
				int ptx = list_points[j].first;
				int pty = list_points[j].second;
				if(ptx >= orx && ptx <= enx && pty >= ory && pty <= eny)
					++num_rect;
			}
			if (num_rect > ans)
				ans = num_rect;
		//}
	}

	cout << ans << endl;

	return 0;
}
