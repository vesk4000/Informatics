#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Source {
	int id, dist, magic;

	Source(int id, int dist, int magic)
			: id(id), dist(dist), magic(magic) {}
};

struct QueuedNode {
	int id, ans;

	QueuedNode(int id, int ans)
			: id(id), ans(ans) {}
};

int clamp(int x, int down = 0, int up = numeric_limits<int>::max()) {
	if(down > up)
		swap(down, up);
	if(x < down)
		return down;
	if(x > up)
		return up;
	return x;
}

int n;
const int MAXN = 2000 + 1;

int m;
const int MAXM = 5000;

vector<Source> srcs[MAXN];

int ans[MAXN];

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int from, to, dist, magic;
		cin >> from >> to >> dist >> magic;
		srcs[to].emplace_back(from, dist, magic);
	}

	for(int i = 1; i <= n; ++i) {
		ans[i] = numeric_limits<int>::max();
	}

	queue<QueuedNode> q;
	q.emplace(n, 0);
	ans[n] = 0;
	
	while(!q.empty()) {
		QueuedNode curr_node = q.front();
		q.pop();

		if(curr_node.ans > ans[curr_node.id])
			continue;
		
		for(int i = 0; i < srcs[curr_node.id].size(); ++i) {
			Source curr_src = srcs[curr_node.id][i];

			//cout << curr_node.id << " " << curr_node.ans << " " << curr_src.id << " " << curr_src.dist << " " << curr_src.magic << endl;

			int potential_ans = clamp(ans[curr_node.id] - curr_src.magic) + curr_src.dist;
			if(potential_ans < ans[curr_src.id]) {
				ans[curr_src.id] = potential_ans;
				q.emplace(curr_src.id, ans[curr_src.id]);
			}
		}
	}

	if(ans[1] == numeric_limits<int>::max())
		cout << -1 << endl;
	else
		cout << ans[1] << endl;
}

/*
7 8
1 2 1 0
2 4 1 0
4 6 1 0
6 7 3 5
1 3 5 2
3 5 2 3
5 7 3 0
3 4 3 1
*/