//Dijkstra
#include <iostream>
#include <vector>

using namespace std;

int n;///number of vertexes
const int maxn = 1024;///the maximum number n can be
int m;///number of edges

int gs;///global variable holding the starting vertex

struct structEdges
{
    int ver;
    int cost;
};

vector <structEdges> nb[maxn];

///Declare functions
void input();
void dijkstra(int s);

int main()
{
    input();
    dijkstra(gs);
    return 0;
}

///Input
void input()
{
    cin >> n >> m;

    for(int i = 0;i < m; ++i)
    {
        int from, to, cost;
        structEdges c;

        cin >> from >> to >> cost;

        c.ver = to;
        c.cost = cost;
        nb[from].push_back(c);

        //*For directed graphs remove the second '/'
        c.ver = from;
        nb[to].push_back(c);
        //*/
    }

    cin >> gs;
}

///Dijkstra
void dijkstra(int s)
{
    vector <int> q;///a simulated priority queue

    q.push_back(s);
}
