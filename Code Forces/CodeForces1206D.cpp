// https://codeforces.com/contest/1206/problem/D
// Verdict: Accepted
// This problem is just about checking for a simple cycle with length 3,
// which happens when there are more than 2 numbers, who have flipped on bits
// on the same position
// Example: 0110, 0011, 0010 - these 3 numbers will create a cycle with length 3
// If there are no such numbers then we can just generate a graph and
// use BFS  to find the shortest cycle, which is fine despite being bruteforce,
// because in that case the maximum number of nodes in the graph will be 120
// This code is largely a copy-paste of Informatics/Algorithms/Graphs/FindShortestCycleInGraph.cpp
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;


const int MAXN = 100000; // Max number of nodes (100 000)
long long int a[MAXN];
vector<int> bits[64];

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


bool bit(long long int num, int bit_place) {
	return (num >> bit_place) & 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	/// Prepare for graph generation and check for obvious cycle with length 3
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
			int n1 = bits[i][0];
			int n2 = bits[i][1];
			// Check if the 2 nodes are already connected
			bool are_connected = false;
			for(int j = 0; j < nbs[n1].size(); ++j)
				if(nbs[n1][j] == n2) {
					are_connected = true;
					break;
				}
			if(!are_connected) {
				nbs[n1].push_back(n2);
				nbs[n2].push_back(n1);
			}
		}

	cout << find_shortest_cycle() << endl;
	return 0;
}