#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Neighbour {
	int id, dist, magic;

	Neighbour(int id, int dist, int magic)
			: id(id), dist(dist), magic(magic) {}
};

struct QueuedNeighbour {
	int curr_dist, curr_magic, id, dist, magic;

	QueuedNeighbour(int curr_dist, int curr_magic, int id, int dist, int magic)
			: curr_dist(curr_dist), curr_magic(curr_magic), id(id), dist(dist), magic(magic) {}
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
const int MAXN = 2000;

int m;
const int MAXM = 5000;

vector<Neighbour> nbs[MAXN];

int ans[MAXN];

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int from, to, dist, magic;
		cin >> from >> to >> dist >> magic;
		nbs[from].emplace_back(to, dist, magic);
	}

	queue<QueuedNeighbour> q;
	q.emplace(0, 0, 1, 0, 0);
	
	while(!q.empty()) {
		QueuedNeighbour curr = q.front();
		q.pop();
		
		int dist_after_magic = clamp(curr.dist - curr.curr_magic);
		int new_curr_magic = clamp(curr.curr_magic - curr.dist);

		
	}
}