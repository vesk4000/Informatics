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

vector<pair<int, int>> list_points;

int ans = 0;


bool sort_by_x_cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

/*bool sort_by_x_cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> w >> h;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		list_points.push_back({x, y});
	}

	sort(list_points.begin(), list_points.end(), sort_by_x_cmp);

	for(int i = 0; i < n; ++i) {
		//cout << list_points[i].first << " " << list_points[i].second << endl;
		int orx = list_points[i].first;
		int ory = list_points[i].second;
		int enx = orx - w;
		int eny = ory - h;
		/*swap(orx, enx);
		swap(ory, eny);*/
		int d = orx;
		orx = enx;
		enx = d;
		d = ory;
		ory = eny;
		eny = d;


		/// Binary search for the first point in the rectangle
		int l = 0, r = i;
		while(true) {
			//cout << l << " " << r << endl;
			if(l >= r)
				break;
			if(l == r - 1)
				if(list_points[l].first >= orx)
					break;
				else {
					l = r;
					break;
				}
			int mid = (r - l) / 2 + l;
			if(list_points[mid].first < orx)
				l = mid;
			else
				r = mid;
		}


		/// Check if there is a possible rectangle
		/*if( hash_points.find(coords2num(enx, eny)) != hash_points.end()
				&& hash_points.find(coords2num(orx + w, ory)) != hash_points.end()
				&& hash_points.find(coords2num(orx, ory + h)) != hash_points.end()) {*/
			/// Check all points to see if they are within the rectangle
			int num_rect = 0;
			for(int j = l; j <= i; ++j) {
				int ptx = list_points[j].first;
				int pty = list_points[j].second;
				if(/*ptx >= orx && ptx <= enx && */pty >= ory && pty <= eny)
					++num_rect;
			}
			if (num_rect > ans)
				ans = num_rect;
		//}
	}

	cout << ans << endl;

	return 0;
}
