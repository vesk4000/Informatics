#include <iostream>
#include "sqsort.h"
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*const int multiplier = 2000;

int coords2num(int i, int j) { /// Convert coordinates to number
	return i * multiplier + j;
}

int coords2num(pair<int, int> coords) {
	return coords2num(coords.first, coords.second);
}

pair<int, int> num2coords(int num) {
	return make_pair<int, int> (num / multiplier, num % multiplier);
}*/

vector<pair<int,int>> ans;

void merge_sort(int l, int r) {
	
	if(l == r) {
		return;
	}
	if(l == r - 1) {
		if(cmp(ans[l].first, ans[l].second, ans[r].first, ans[r].second))
			swap(ans[l], ans[r]);
		return;
	}

	merge_sort(l, l + (r - l) / 2);
	merge_sort(l + (r - l) / 2 + 1, r);

	int i = l;
	int max_i = l + (r - l) / 2;
	int j = l + (r - l) / 2 + 1;
	int max_j  = r;

	vector<pair<int, int>> new_ans;
	cout << l << " " << r << endl;
	cout << i << " " << max_i << " " << j << " " << max_j << endl;
	while(i <= max_i || j <= max_j) {
		/// If first pair is smaller than second pair
		cout << i << " " << j << endl;
		if(i == max_i) {
			for(; j <= max_j; ++j)
				new_ans.push_back(ans[j]);
			
		} else if (j == max_j) {
			for(; i <= max_i; ++i)
				new_ans.push_back(ans[i]);
		}
		else {
			//cout << i << " " << j << endl;
			cout << ans[i].first << " " << ans[i].second << " " << ans[j].first << " " << ans[j].second << endl;
			if(cmp(ans[i].first, ans[i].second, ans[j].first, ans[j].second)) { 
				new_ans.push_back(ans[i]);
				++i;
			}
			else {
				new_ans.push_back(ans[j]);
				++j;
			}
		}
	}

	for(int k = l; k < new_ans.size() + l; ++k)
		ans[k] = new_ans[k - l];
}

int qrs;

struct {
        bool operator()(pair<int, int> a, pair<int, int> b) const
        {   
			qrs++;
            return cmp(a.first, a.second, b.first, b.second);
        }   
    } customLess;

vector<pair<int,int>> solve(int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			/*cout << i << " " << j << " " << coords2num(i, j) << " " << num2coords(coords2num(i, j)).first
			<< " " << num2coords(coords2num(i, j)).second << endl;*/
			ans.push_back(make_pair(i, j));
		}
	}
	//cout << "solving" << endl;
	//merge_sort(0, n * n - 1);
	sort(ans.begin(), ans.end(), customLess);
	//cout << qrs << endl;
	/*for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}*/
	return ans;
}