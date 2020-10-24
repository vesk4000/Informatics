// Find shortest cycle in an unweighed undirected graph
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;


const int MAXN = 100000; // Max number of nodes (100 000)
vector<int> active_nodes; // Node which have neighbours in them
vector<int> nbs[MAXN]; // Neighbours of each node
int dist[MAXN]; // Distance to each node
int parents[MAXN]; // Parent of each node


int find_shortest_cycle() {
	int ans = numeric_limits<int>::max(); // Length of the shortest cycle

	// Find all the nodes which have neighbours and "activate" them
	for(int i = 0; i < MAXN; ++i)
		if(nbs[i].size() > 0)
			active_nodes.push_back(i);
	
	// For all nodes run BFS with them as a root node
	for(int i = 0; i < active_nodes.size(); ++i) {
		// Reset all arrays
		for(int j = 0; j < active_nodes.size(); ++j) {
			dist[active_nodes[j]] = -1;
			parents[active_nodes[j]] = -1;
		}

		queue<int> evl; // Nodes that should be evaluated
		evl.push(active_nodes[i]); // Push root node into the evaluation queue
		dist[active_nodes[i]] = 0;
		while(!evl.empty()) {
			int c = evl.front(); // Currently evaluated node
			evl.pop();
			// Loop through its neighbours
			for(int j = 0; j < nbs[c].size(); ++j) {
				int cnb = nbs[c][j]; // Current neighbour
				if(dist[cnb] == -1) {
					dist[cnb] = dist[c] + 1;
					evl.push(cnb);
					parents[cnb] = c;
				}
				else if(parents[c] != cnb) {
					// We have found a cycle
					// This is only really accurate for the length of the cycle
					// when the node at which the two paths diverge is
					// the current root node, otherwise it is more than the
					// actual length of the cycle, but that is OK, because we
					// run BFS on all nodes, so at some point it will be accurate
					ans = min(ans, dist[c] + dist[cnb] + 1);
				}
			}
		}
	}
	
	if(ans == numeric_limits<int>::max())
		ans = -1;
	return ans;
}


void create_graph() {
	int m; // Number of edges
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		nbs[n1].push_back(n2);
		nbs[n2].push_back(n1);
	}
}


int main() {
	create_graph();
	cout << find_shortest_cycle() << endl;
	return 0;
}