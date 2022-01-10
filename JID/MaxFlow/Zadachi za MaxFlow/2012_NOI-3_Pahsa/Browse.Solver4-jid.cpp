/*
ID: espr1t
LANG: C++
TASK: Browse
KEYWORDS: Solver
*/

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1024
#define EPS 0.0000001
using namespace std;

struct Point
{
    double x, y;
};

int n, m, k;
Point a[MAX], b[MAX];
double pdist[MAX][MAX];


// Push-Relabel Flow -->
// ============================

template <class Type> class Flow
{
	public:

	struct Edge
	{
		Type cap;
		int to, next;
		Edge(int to_ = 0, Type cap_ = 0, int next_ = -1) {to = to_; cap = cap_; next = next_;}
	};

	int brV;
	int globalRelabel;
	vector <int> first;
	vector <Edge> E;

	vector <int> Lev;
	vector <Type> excess;

	void init(int n)
	{
		brV = n;
		globalRelabel = 0;

		first.clear(); first.resize(n, -1);
		excess.clear(); excess.resize(n, 0);
		Lev.clear(); Lev.resize(n, 0);
	}

	void addEdge(int b, int e, Type cap)
	{
		E.push_back( Edge(e, cap, first[b]) );
		first[b] = E.size() - 1;

		E.push_back( Edge(b, 0, first[e]) );
		first[e] = E.size() - 1;
	}

	void Bfs(int s)
	{
	    curQ.push(s);
		while (!curQ.empty())
		{
			while (!curQ.empty())
			{
				int cur = curQ.front(); curQ.pop();
				for (int ind = first[cur]; ind != -1; ind = E[ind].next)
				{
					if (E[ind ^ 1].cap > 0 && Lev[ E[ind].to ] == -1) /// if (E[ind ^ 1 ].cap > 0 && Lev[E[ind].to] == -1)
					{
						Lev[E[ind].to] = Lev[cur] + 1;
						nextQ.push(E[ind].to);
					}
				}
			}
			swap(curQ, nextQ);
		}
	}

	void updateGr(int src, int sink)
	{
		globalRelabel = 0;
		queue <int> curQ, nextQ;

		for (int i = 0; i < (int)Lev.size(); i++)
			Lev[i] = -1;
		Lev[src] = brV;
		Lev[sink] = 0;
		Bfs(sink);
        Bfs(src);
	}

	Type findFlow(int src, int sink)
	{
		Lev[src] = brV;
		Lev[sink] = 0;

		queue <int> q;
		for (int ind = first[src]; ind != -1; ind = E[ind].next )
		{
			if ( Lev[E[ind].to] == 0 && E[ind].cap > 0 )
			{
				if (E[ind].to != src && E[ind].to != sink) q.push(E[ind].to);
				excess[E[ind].to] += E[ind].cap;
				E[ind ^ 1].cap += E[ind].cap;
				E[ind].cap = 0;
			}
		}

		while(!q.empty())
		{
			int cur = q.front(); q.pop();
			if ( globalRelabel++ >= brV * 2 ) updateGr(src, sink);

			int next = -1;
			for (int ind = first[cur]; ind != -1; ind = E[ind].next)
			{
				if (E[ind].cap > 0)
				{
					if (Lev[E[ind].to] == Lev[cur] - 1)
						{next = ind; break;}
					if ( Lev[E[ind].to] >= Lev[cur] )
					{
						if (next == -1) next = ind;
						else if ( Lev[E[next].to] > Lev[E[ind].to] ) next = ind;
					}
				}
			}
			if (next == -1) continue;
			if (Lev[E[next].to] > Lev[cur] - 1)
				Lev[cur] = Lev[E[next].to] + 1;

			Type flow = min(excess[cur], E[next].cap);
			excess[E[next].to] += flow;
			excess[cur] -= flow;
			E[next].cap -= flow;
			E[next ^ 1].cap += flow;

			if (excess[cur] > 0) q.push(cur);
			if ( E[next].to != src && E[next].to != sink && excess[E[next].to] == flow)
				q.push(E[next].to);
		}
		return excess[sink];
	}
};

// ============================
// <-- End of Push-Relabel Flow


bool eval(double maxDist)
{
	Flow <int> flow;
	flow.init(n + m + 2);

    for (int i = 0; i < n; i++)
        flow.addEdge(n + m, i, 1);
    for (int i = 0; i < m; i++)
        flow.addEdge(n + i, n + m + 1, k);
    for (int i = 0; i < n; i++)
        for (int c = 0; c < m; c++)
            if (pdist[i][c] < maxDist + EPS)
                flow.addEdge(i, n + c, 1);
    int ans = flow.findFlow(n + m, n + m + 1);
    return ans == n;
}

void solveTest(int testNum)
{
    char inpFile[32], outFile[32];
    sprintf(inpFile, "Browse.%02d.in", testNum);
    sprintf(outFile, "Browse.%02d.out", testNum);
    FILE* in = fopen(inpFile, "rt");
    FILE* out = fopen(outFile, "wt");

    fscanf(in, "%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        fscanf(in, "%lf %lf", &a[i].x, &a[i].y);
    for (int i = 0; i < m; i++)
        fscanf(in, "%lf %lf", &b[i].x, &b[i].y);

    for (int i = 0; i < n; i++)
    	for (int c = 0; c < m; c++)
    		pdist[i][c] = sqrt((a[i].x - b[c].x) * (a[i].x - b[c].x) +
    						   (a[i].y - b[c].y) * (a[i].y - b[c].y));

    vector <double> distances;
    for (int i = 0; i < n; i++)
    	for (int c = 0; c < m; c++)
    		distances.push_back(pdist[i][c]);
    sort(distances.begin(), distances.end());
    distances.resize(unique(distances.begin(), distances.end()) - distances.begin());

    double ans = distances.back();
    int left = 0, right = (int)distances.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (eval(distances[mid]))
            ans = min(ans, distances[mid]), right = mid - 1;
        else left = mid + 1;
    }
    fprintf(out, "%.6lf\n", ans);
    fclose(in); fclose(out);

	/*
    sprintf(inpFile, "Browse.%02d.sol", testNum);
    in = fopen(inpFile, "rt");
    double real;
    fscanf(in, "%lf", &real);
    if (fabs(real - ans) < 0.000001)
    	fprintf(stderr, "Answers match.\n");
    else
    	fprintf(stderr, "Answers are different (%.6lf vs %.6lf)\n", ans, real);
    */
}

int main(void)
{
    int numTests = 20;
    for (int test = 0; test <= numTests; test++)
    {
        unsigned sTime = clock();
        fprintf(stderr, "Solving test case %d...", test);
        solveTest(test);
        fprintf(stderr, " Execution time: %.3lfs.\n",
            (double)(clock() - sTime) / CLOCKS_PER_SEC);
    }
    fprintf(stderr, "Finished solving test cases.\n");
    system("pause");
    return 0;
}
