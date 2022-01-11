#include <iostream>
#include <queue>
using namespace std;

int n;
const int MAXN = 5 * 1e5;

int w[MAXN];
int p[MAXN];
int cap[MAXN];
int miners[MAXN];

int input_miners[MAXN];
int input_cap[MAXN];

int mx[MAXN];

queue<int> leaves;
int num_children[MAXN];
bool used[MAXN];

int mx_child[MAXN];
int mx_parent;

vector<int> children[MAXN];

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> input_miners[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> input_cap[i];
	}
	for(int i = 2; i <= n; ++i) {
		cin >> p[i] >> w[i];
		children[p[i]].push_back(i);
	}

	/*
	n = 5;
	init[1] = 5;
	init[2] = 1;
	init[3] = 0;
	init[4] = 0;
	init[5] = 0;
	cap[1] = 100;
	cap[2] = 1;
	cap[3] = 1;
	cap[4] = 2;
	cap[5] = 4;
	p[1] = -1;
	w[1] = 0;
	p[2] = 1;
	w[2] = 6;
	p[3] = 1;
	w[3] = 1;
	p[4] = 2;
	w[4] = 2;
	p[5] = 2;
	w[5] = -1;
	*/

	int sum = 0;

	for(int i = 2; i <= n; ++i)
		++num_children[p[i]];
	
	vector<int> top_sort;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		for(int i = 0; i < children[q.front()].size(); ++i) {
			q.push(children[q.front()][i]);
		}
		top_sort.push_back(q.front());
		q.pop();
	}


	while(true) {
		for(int i = top_sort.size() - 1; i >= 0 ; --i) {
			leaves.push(top_sort[i]);
			cout << top_sort[i] << endl;

		}		
		for(int i = 1; i <= n; ++i) {
			used[i] = false;
			mx_child[i] = i;
			miners[i] = input_miners[i];
			cap[i] = input_cap[i];
			if(cap[i] == 0)
				mx[i] = -1e8;
			else
				mx[i] = 0;
		}
		mx_parent = -1;
		used[1] = true;
		int ans = 0;

		while(!leaves.empty()) {
			int leaf = leaves.front();
			leaves.pop();
			if(cap[leaf] == 0 || used[leaf])
				continue;
			used[leaf] = true;
			if(mx[leaf] + w[leaf] > mx[p[leaf]] || (mx[leaf] + w[leaf] == mx[p[leaf]] && )) {
				mx[p[leaf]] = mx[leaf] + w[leaf];
				cap[p[leaf]] = cap[leaf];
				mx_child[p[leaf]] = mx_child[leaf];
				if(miners[p[leaf]] > 0) {
					if(mx[p[leaf]] > ans) {
						ans = mx[p[leaf]];
						mx_parent = p[leaf];
					}
				}
					
			}
			leaves.push(p[leaf]);
		}

		//cout << mx_parent << " " << mx_child[mx_parent] << endl << endl;
		if(ans <= 0)
			break;
		if(input_miners[mx_parent] < input_cap[mx_child[mx_parent]]) {
			sum += ans * input_miners[mx_parent];
			input_cap[mx_child[mx_parent]] -= input_miners[mx_parent];
			input_miners[mx_parent] = 0;
		}
		else {
			sum += ans * input_cap[mx_child[mx_parent]];
			input_miners[mx_parent] -= input_cap[mx_child[mx_parent]];
			input_cap[mx_child[mx_parent]] = 0;
		}
	}

	cout << sum << endl;

	return 0;
}