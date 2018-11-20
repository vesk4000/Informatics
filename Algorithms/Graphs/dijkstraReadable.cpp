#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

///Declare functions, so you can place their code after "main()"
void input();
void dijkstra();
void output();
string restorePath(int node);
string convertToString(int num);

///Create a class to store the neighbors of all the nodes
struct neighbour {
	int node;///The neighbouring node
	int cost;///The cost of the edge connecting the two nodes
};

///Declare global variables
int numNodes;
const int maxNumNodes = 1024;
int numEdges;
vector <neighbour> nb[maxNumNodes];///The neighbours of node I is stored in the vector nb[I]
int startingNode;

///Variables for Dijkstra
int dist[maxNumNodes];///The distance from the starting node to I; can't use distance cuz it's in std and we are using namespace std;
int parent[maxNumNodes];///The previous node on the path from I to the starting node
bool used[maxNumNodes];///Have we been through I

int main() {
	input();
	dijkstra();
	output();
	return 0;
}

void dijkstra() {
	///Set the distance[] for all nodes to max so that
	///any value we get as a result of Dijkstra is less and preferable
	for(int i = 0;i < numNodes; ++i)
		dist[i] = numeric_limits<int>::max();
	dist[startingNode] = 0;///The dist from the starting node to -//- is always 0

	vector <int> toBeEvaled;///A vector containing the indexes of the nodes, which are to be evaluated
	toBeEvaled.push_back(startingNode);

	while(!toBeEvaled.empty()) {
		///Find the position of the node closest to the startingNode in toBeEvaled
		int closestNode;
		int lowestDist = numeric_limits<int>::max();///any other value is lower
		for(int i = 0;i < toBeEvaled.size(); ++i) {
			if(dist[toBeEvaled[i]] < lowestDist) {
				lowestDist = dist[toBeEvaled[i]];
				closestNode = i;
			}
		}

		int currNode = toBeEvaled[closestNode];
		toBeEvaled.erase(toBeEvaled.begin() + closestNode);///We are now evaluating closestNode
		used[currNode] = true;

		///Loop through the neighbours of the current node
		for(int i = 0;i < nb[currNode].size(); ++i) {
			neighbour currNb = nb[currNode][i];
			if( used[ currNb.node ] == false
			 && dist[currNode] + currNb.cost < dist[ currNb.node ]) {

			 	dist[currNb.node] = dist[currNode] + currNb.cost;
			 	toBeEvaled.push_back(currNb.node);
			 	parent[currNb.node] = currNode;
			}
		}
	}


}

void input() {
	cin >> numNodes;
	cin >> numEdges;

	///Enter the edges in the format: node1/nodeTheEdgeStartsAt node2/-//-EndsAt costOfEdge
	for(int i = 0;i < numEdges; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;

		neighbour toInsert;///Temporary neighbour to insert in nb
		toInsert.cost = cost;

		toInsert.node = to;
		nb[from].push_back(toInsert);

		///Only for undirected graphs
		toInsert.node = from;
		nb[to].push_back(toInsert);
	}
}

void output() {
	cout << "node used dist path" << endl;
	for(int i = 0;i < numNodes; ++i) {
		cout << i << ": " << used[i] << "; " << dist[i] << "; " << restorePath(i) << ";\n";
	}
}

string restorePath(int node) {
	if(node == startingNode)
		return convertToString(node);
	else
		return convertToString(node) + " " + restorePath(parent[node]);
}

string convertToString(int num)
{
    ostringstream convert;
    convert << num;
    string result = convert.str();
    return result;
}
