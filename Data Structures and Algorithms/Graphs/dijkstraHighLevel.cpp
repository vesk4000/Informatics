///Not done
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

///Declare functions
void input();
void dijkstra();
void output();
bool compare(int node1, int node2);

///Graph variables, so we don't have to put the whole graph in a class
int numNodes;
const int maxNumNodes = 1024;
int firstNode;
int lastNode;
int numEdges;
int startingNode;///For dijkstra
struct neighbour {
	int node;
	int cost;
};
struct node {
	int dist = numeric_limits<int>::max();
	bool known = false;
	//bool inQueue = false;
	int parent = -1;
	vector <neighbour> nb;
};
node nodes[maxNumNodes];

int main() {

	input();
	dijkstra();
	output();
	return 0;
}

void dijkstra() {
	priority_queue<int, vector<int>, bool (*)(int, int)> toBeEvaled(compare);
	for(int i = firstNode;i <= lastNode; ++i)
		toBeEvaled.push(i);
}

///A compare function for the priority queue
bool compare(int node1, int node2) {
	return nodes[node1].dist < nodes[node2].dist;
}

void input() {
	cin >> numNodes >> numEdges;
	firstNode = 0;
	lastNode = numNodes - 1;
	for(int i = 0;i < numEdges; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		neighbour toInsert;
		toInsert.cost = cost;

		toInsert.node = to;
		nodes[from].nb.push_back(toInsert);

		///Only for undirected graphs
		toInsert.node = from;
		nodes[to].nb.push_back(toInsert);
	}
}
