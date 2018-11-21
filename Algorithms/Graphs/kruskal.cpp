#include <iostream>
#include <algorithm>
using namespace std;

///Declare functions
void input();
int kruskal();
int findSetRoot(int a);
void mergeTrees(int a, int b);

///Represent the graph as an array of edges
int numNodes;
const int MAX_NUM_NODES = 1024;
int numEdges;
const int MAX_NUM_EDGES = 4092;
struct Edge {
	int a, b, cost;///node1, node2
};
Edge edges[MAX_NUM_EDGES];
int lastParent[MAX_NUM_NODES];
int treeSize[MAX_NUM_NODES];

bool compareEdges(Edge a, Edge b);

int main() {
	input();
	cout << kruskal() << endl;
	for(int i = 0;i < numNodes; ++i)
		cout << i << " " << lastParent[i] << endl;
	return 0;
}

void input() {
	cin >> numNodes >> numEdges;
	for(int i = 0;i < numEdges; ++i) {
		cin >> edges[i].a >> edges[i].b >> edges[i].cost;
	}
}

int kruskal() {
	sort(edges, edges + numEdges, compareEdges);
	cout << 1 << endl;
	int sum = 0;
	int numAddedEdges = 0;
	for(int i = 0;i < numNodes; ++i) {
		lastParent[i] = i;
		treeSize[i] = 1;
	}

	for(int i = 0;i < numEdges; ++i) {

		if(findSetRoot(edges[i].a) != findSetRoot(edges[i].b)) {
			mergeTrees(edges[i].a, edges[i].b);
			sum += edges[i].cost;
			++numAddedEdges;
		}
		cout << edges[i].a << " " << edges[i].b << " " << edges[i].cost << endl;
	}
	return sum;
}

int findSetRoot(int a) {
	if(lastParent[a] == a)
		return a;
	return lastParent[a] = findSetRoot(lastParent[a]);
}

void mergeTrees(int a, int b) {
	int aRoot = findSetRoot(a);
	int bRoot = findSetRoot(b);

	if(treeSize[aRoot] < treeSize[bRoot]) {
		lastParent[aRoot] = bRoot;
		treeSize[bRoot] += treeSize[aRoot];
		treeSize[aRoot] = 0;
	}
	else {
		lastParent[bRoot] = aRoot;
		treeSize[aRoot] += treeSize[bRoot];
		treeSize[bRoot] = 0;
	}
}

bool compareEdges(Edge a, Edge b) {
	if(a.cost < b.cost)
		return true;
	return false;
}
