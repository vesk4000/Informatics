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

vector<pair<int, int>> vec;

int ans = 0;


bool sort_by_x_cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> w >> h;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end(), sort_by_x_cmp);

	for(int x = 0; x <= 100; ++x) {
		for(int y = 0; y <= 100; ++y) {
			int urx = x + w;
			int ury = y + h;
			int num_rect = 0;
			for(int i = 0; i < vec.size(); ++i) {
				if(vec[i].first > urx)
					break;
				if(vec[i].first >= x && vec[i].first <= urx && vec[i].second >= y && vec[i].second <= ury)
					++num_rect;
				if (num_rect > ans)
				ans = num_rect;
			}
		}
		if(x > vec[vec.size() - 1].first)
			break;
	}

	/*for(int i = 0; i < n; ++i) {
		//cout << vec[i].first << " " << vec[i].second << endl;
		int orx = vec[i].first;
		int ory = vec[i].second;
		int enx = orx - w;
		int eny = ory - h;
		swap(orx, enx);
		swap(ory, eny);

		/// Binary search for the first point in the rectangle
		int l = 0, r = i;
		while(true) {
			//cout << l << " " << r << endl;
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


		/// Check if there is a possible rectangle
		/*if( hash_points.find(coords2num(enx, eny)) != hash_points.end()
				&& hash_points.find(coords2num(orx + w, ory)) != hash_points.end()
				&& hash_points.find(coords2num(orx, ory + h)) != hash_points.end()) {*/
			/// Check all points to see if they are within the rectangle
			/*int num_rect = 0;
			for(int j = l; j <= i; ++j) {
				int ptx = vec[j].first;
				int pty = vec[j].second;
				if(/*ptx >= orx && ptx <= enx && *///pty >= ory && pty <= eny)
					/*++num_rect;
			}
			if (num_rect > ans)
				ans = num_rect;
		//}
	}*/

	cout << ans << endl;

	return 0;
}
