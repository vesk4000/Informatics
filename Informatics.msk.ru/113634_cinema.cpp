// https://informatics.msk.ru/mod/statements/view.php?chapterid=113634#1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*const long long int MAXN = 1e9;
vector<int> seats_taken[MAXN + 1]; // for each row
*/
const int MAXM = 1e5;
vector<pair<int, int>> taken_seats;
int n, m, k;
int rb, cb;



int calc_failure(int row, int col) {
	return abs(row - rb) + abs(col - cb);
}

int calc_interval(int row, int l, int r) {
	if(r < l)
		return -1;
	if(r - l + 1 < k)
		return -1;
	int closest;
	if(r <= cb)
		closest = r;
	else if(l >= cb)
		closest = l;
	else
		closest = cb;
	
	int closest_failure = calc_failure(row, closest);
	//cout << closest_failure << endl;

	int space_on_lr;
	bool closer_to_right = abs(r - closest) < abs(l - closest);
	if(closer_to_right)
		space_on_lr = abs(r - closest);
	else
		space_on_lr = abs(l - closest);
	int space_taken = 2 * space_on_lr + 1;
	//cout << space_on_lr << endl;
	int failure = closest_failure + space_on_lr * (closest_failure + 1 + closest_failure + space_on_lr);
	failure += (k - space_taken) * ((closest_failure + space_on_lr + 1) + (closest_failure + space_on_lr + (k - space_taken) )) / 2;
	return failure;
}

int mn = -1;

void calc_min(pair<int, int> l, pair<int, int> r) {
	int curr = calc_interval(l.first, l.second + 1, r.second - 1);
	if(curr != -1) {
		if(mn == -1) {
			mn = curr;
			//cout << l.first << " " << l.second << " " << r.first << " " << r.second << endl;
		}
			
		else
			if(mn > curr) {
				mn = curr;
				
			}
	}
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}



int main() {
	taken_seats.reserve(MAXM * 3);
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i) {
		int r, c;
		cin >> r >> c;
		taken_seats.push_back({r, c});
	}
	cin >> rb >> cb;
	
	sort(taken_seats.begin(), taken_seats.end(), cmp);
	
	/*if(taken_seats.size() == 0)
		inbetween = rb;*/
	int prev_row = -1;
	int inbetween = -1;

	for(int i = 0; i < taken_seats.size(); ++i) {
		if(taken_seats[i].first == rb)
			inbetween = i;
		pair<int, int> l, r;
		if(prev_row != taken_seats[i].first) {
			l = {taken_seats[i].first, 0};
			r = taken_seats[i];
		}
		else {
			l = taken_seats[i - 1];
			r = taken_seats[i];
		}
		calc_min(l, r);
		if(i == taken_seats.size() - 1 || taken_seats[i].first != taken_seats[i + 1].first) {
			l = taken_seats[i];
			r = {taken_seats[i].first, n + 1};
			calc_min(l, r);
		}

		prev_row = taken_seats[i].first;
	}
	if(inbetween == -1) {
		calc_min({rb, 1}, {rb, n});
	}
	else {
		int closest_empty_row = rb - 1;
		prev_row = rb;
		for(int i = inbetween - 1; i >= 0; --i) {
			if(prev_row != taken_seats[i].first) {
				if(closest_empty_row == taken_seats[i].first)
					closest_empty_row--;
				else
					break;
			}
			prev_row = taken_seats[i].first;
		}
		int lrow = closest_empty_row;

		closest_empty_row = rb + 1;
		prev_row = rb;
		for(int i = inbetween + 1; i < taken_seats.size(); ++i) {
			if(prev_row != taken_seats[i].first) {
				if(closest_empty_row == taken_seats[i].first)
					closest_empty_row++;
				else
					break;
			}
			prev_row = taken_seats[i].first;
		}
		int rrow = closest_empty_row;
		
		if(lrow < 1) {
			if(rrow <= n) {
				calc_min({rrow, 0}, {rrow, n + 1});
			}
		}
		else {
			if(rrow > n) {
				calc_min({lrow, 0}, {lrow, n + 1});
			}
			else {
				if(abs(rrow - rb) < abs(lrow - rb))
					calc_min({rrow, 0}, {rrow, n + 1});
				else 
					calc_min({lrow, 0}, {lrow, n + 1});
			}
		}
	}

	cout << mn << endl;

	/*int row, left, right;
	cin >> row >> left >> right;
	cout << calc_interval(row, left, right) << endl;*/

	/*	int minn = -1;

	for(int i = 1; i <= n; ++i) {
		seats_taken[i].push_back(0);
		seats_taken[i].push_back(n + 1);
		sort(seats_taken[i].begin(), seats_taken[i].end());
		for(int j = 0; j < seats_taken[i].size() - 1; ++j) {
			int potent_min = calc_interval(i, seats_taken[i][j] + 1, seats_taken[i][j + 1] - 1);
			if(potent_min != -1) {
				if(minn == -1)
					minn = potent_min;
				else
					minn = min(potent_min, minn);
			}
		}
	}

	cout << minn << endl;*/

	return 0;
}