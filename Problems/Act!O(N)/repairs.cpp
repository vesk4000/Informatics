#include <bits/stdc++.h>
#define MAXN 101000
using namespace std;

struct edge
{
    int a, b;
    int weight;
};
long long edgeSum;

edge edges[MAXN];
int parent[MAXN];
long long d[MAXN];
int edgeCnt;
int vertCnt;

int find(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void merge(int a, int b)
{
    int aRoot = find(a);
    int bRoot = find(b);

    if (d[aRoot] < d[bRoot]) parent[aRoot] = bRoot;
    else if (d[aRoot] > d[bRoot]) parent[bRoot] = aRoot;
    else
    {
        parent[aRoot] = bRoot;
        d[bRoot]++;
    }
}

bool compareEdges(edge a, edge b)
{
    if (a.weight < b.weight) return true;
    return false;
}

int kruskal()
{
    sort (edges, edges + edgeCnt, compareEdges);
    long long sum = 0;
    int addedEdges = 0;

    for (int i = 0; i < vertCnt; i++)
        parent[i] = i;


    for (int i = 0; i < edgeCnt; i++)
        if (find(edges[i].a) != find(edges[i].b))
        {
            merge(edges[i].a, edges[i].b);
            sum += edges[i].weight;
            addedEdges++;
        }

    if (addedEdges < vertCnt - 1) return -1;
    return sum;
}

void input()
{
    cin >> vertCnt >> edgeCnt;

    for(int i = 0; i < edgeCnt; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].weight;
        edgeSum += edges[i].weight;
        edges[i].a--;
        edges[i].b--;
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    long long kruskalOutput = kruskal();
    if(kruskalOutput == -1)
        cout << -1 << endl;
    else
        cout << edgeSum - kruskalOutput << endl;
}
