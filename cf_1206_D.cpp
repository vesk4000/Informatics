//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;


int n;
const int MAXN = 100000;///100 000
long long int a[MAXN];
vector<int> bits[64];

vector<int> nb[MAXN];
unordered_set<int> unused_set;
int level[MAXN];
int parents[MAXN];


bool bit(long long int num, int bit_place) {
	return (num >> bit_place) & 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	/// Prepare for graph generation and check for obvious solution
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 64; ++j)
			if(bit(a[i], j)) {
				if(bits[j].size() >= 2) {
					cout << 3 << endl;
					return 0;
				}
				else
					bits[j].push_back(i);
			}

	/// Generate graph
	for(int i = 0; i < 64; ++i)
		if(bits[i].size() == 2) {
		nb[bits[i][0]].push_back(bits[i][1]);
		nb[bits[i][1]].push_back(bits[i][0]);
		unused_set.insert(bits[i][0]);
		unused_set.insert(bits[i][1]);
		//cout << a[bits[i][0]] << " " << a[bits[i][1]] << endl;
	}

	//cout << a[(*used_set.begin())] << endl;

	/// Run BFS
	//memset(parents, -1, sizeof(parents));
	for(int i = 0; i < n; ++i) {
		parents[i] = -1;
	}

	cout << "START BFS" << endl;
	while(unused_set.size()) {
		int s = (*unused_set.begin());
		unused_set.erase(s);
		cout << a[s] << endl;
		queue<int> q; // Nodes to be evaluated
		q.push(s);
		level[s] = 1;
		while(!q.empty()) {
			int c = q.front(); // Current node
			q.pop();
			cout << a[c] << endl;
			for(int i = 0; i < nb[q.front()].size(); ++i) {
				int cnb = nb[c][i]; // Current neighbour
				if(level[cnb] == 0) {
					q.push(cnb);
					level[cnb] = level[c] + 1;
					if(unused_set.count(cnb) == 1)
						unused_set.erase(cnb);
					parents[cnb] = c;
				}
				else if(parents[c] != cnb) {
					/// We have found a cycle
					cout << "FOUND CYCLE" << endl;
				}
			}
		}
		if (q.empty())
			cout << "EMPTY QUEUE" << endl;
	}
	
	cout << "END" << endl;
	return 0;
}
