#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN = 250;

int n;
int graph[MAXN+10][MAXN+10];
int A,B;

int sA,sB;
bool TFO[MAXN+10];

void GetAll(int ver,int color)
{
    if (TFO[ver]) return;
    TFO[ver] = true;

    for (int i = 1; i<=n; i++)
    {
        if (graph[ver][i]==color) GetAll(i,color);
    }
    return;
}

void GetState()
{
    sA = sB = 1;
    memset(TFO,false,sizeof(TFO));
    GetAll(1,0);

    for (int i = 1; i<=n; i++)
    {
        if ( !TFO[i] )
        {
            sA = 0;
            break;
        }
    }

    memset(TFO,false,sizeof(TFO));

    GetAll(1,1);

    for (int i = 1; i<=n; i++)
    {
        if (!TFO[i])
        {
            sB = 0;
            break;
        }
    }

    return;
}

///1 1
int L = 0;
vector<int> compon[MAXN+10];

void DFS(int v,int c)
{
    if (TFO[v]) return;

    TFO[v] = true;
    compon[c].push_back(v);

    for (int i = 1; i<=n; i++)
    {
        if ( !graph[v][i] )
            DFS(i,c);
    }
    return;
}

void GetComponents()
{
    memset(TFO,false,sizeof(TFO));
    for (int i = 1; i<=n; i++)
    {
        if (!TFO[i])
        {
            L++;
            DFS(i,L);
        }
    }
    return;
}

///Not 1 1 - flow
int flow[MAXN+10][MAXN+10];
int cap[MAXN+10][MAXN+10];
int SOURCE,TARGET;
vector<int> Path;

vector<int> G[MAXN+10];

bool GetPath(int ver)
{
    if (TFO[ver]) return false;

    TFO[ver] = true;
    Path.push_back(ver);

    if (ver==TARGET) return true;

    for (int i = 0; i< (int)G[ver].size(); i++)
    {
        if ( flow[ver][ G[ver][i] ]<cap[ver][ G[ver][i] ] )
        {
            if (GetPath(G[ver][i])) return true;
        }
    }

    Path.pop_back();

    return false;
}

void Reachables(int ver)
{
    if (TFO[ver])
        return;

    TFO[ver] = true;

    int i;

    for (i = 1; i<=n; i++)
    {
        if (flow[ver][i]<cap[ver][i])
            Reachables(i);
    }

    return;
}

vector< pair<int,int> > Ans;
bool hasans = false;

vector< pair<int,int> > Changes;

void GetCut()
{
    int i,j;

    memset(TFO,false,sizeof(TFO));
    Reachables(SOURCE);

    Changes.clear();
    for (i = 1; i<=n; i++)
    {
        for (j = 1; j<=n; j++)
        {
            if (TFO[i] && !TFO[j]  && cap[i][j]>0)
            {
                Changes.push_back(make_pair(i,j));
            }
        }
    }

    if (!hasans || Ans.size()>Changes.size())
    {
        Ans.clear();

        for (i = 0; i<(int)Changes.size(); i++)
        {
            Ans.push_back(Changes[i]);
        }

        hasans = true;
    }

    return;
}


void SendFlow()
{
    for (int i = 1; i<(int)Path.size(); i++)
    {
        flow[ Path[i-1] ][ Path[i] ]++;
        flow[ Path[i] ][ Path[i-1] ]--;
    }
    return;
}

int q[MAXN+10];
int qL;
int dst[MAXN+10];

bool BFSLevel()
{
    int i,j;
    int uk = 1;
    bool goodret = false;

    for (i = 1; i<=n; i++)
    {
        G[i].clear();
    }

    qL = 1;
    q[1] = SOURCE;
    dst[SOURCE] = 0;
    TFO[SOURCE] = true;

    while(uk<=qL)
    {
        if (q[uk]==TARGET)
        {
            goodret = true;
            break;
        }

        for (i = 1; i<=n; i++)
        {
            if (!TFO[i] && flow[ q[uk] ][i]<cap[ q[uk] ][i])
            {
                qL++;
                q[qL] = i;
                dst[i] = dst[ q[uk] ]+1;
                TFO[i] = true;
            }
        }

        uk++;
    }

    for (i = 1; i<=n; i++)
    {
        for (j = 1; j<=n; j++)
        {
            if (flow[i][j]<cap[i][j] && dst[i]==dst[j]-1)
            {
                G[i].push_back(j);
            }
        }
    }

    return goodret;
}

void GetMinCut()                    ///Ford-Fulkerson
{
    int flowctr = 0;

    memset(TFO,false,sizeof(TFO));
    while(BFSLevel())
    {
        memset(TFO,false,sizeof(TFO));
        Path.clear();
        while(GetPath(SOURCE))
        {
            SendFlow();
            flowctr++;
            Path.clear();
            memset(TFO,false,sizeof(TFO));
        }

        memset(TFO,false,sizeof(TFO));
    }

    GetCut();

    return;
}

void DisconnG()
{
    for (int i = 1; i<=n; i++)
    {
        cap[i][i] = 0;
        for (int j = i+1; j<=n; j++)
        {
            if (graph[i][j]==0) cap[i][j] = cap[j][i] = 1;
            else cap[i][j] = cap[j][i] = 0;
        }
    }

    SOURCE = 1;
    for (int i = 2; i<=n; i++)                  ///Separate 1 from i
    {
        memset(flow,0,sizeof(flow));
        TARGET = i;

        GetMinCut();
    }
    return;
}

///
void FlipInput()
{
    swap(A,B);
    swap(sA,sB);

    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            graph[i][j] ^= 1;
        }
    }
    return;
}

int mydegree[MAXN+10];
vector<int> mixed;

int main()
{
    int isolated, spec;
    int edges = 0;
    int sum = 0;
    int uk = 0;

    scanf("%d",&n);

    for (int i = 1; i<=n; i++)
    {
        sum = 0;
        for (int j = 1; j<=n; j++)
        {
            scanf("%d",&graph[i][j]);
            sum += graph[i][j];
        }
    }

    scanf("%d %d",&A,&B);

    GetState();

    if (A==sA && B==sB)
    {
        printf("0\n");
        return 0;
    }

    if (A==0 && B==0)
    {
        printf("-1\n");
        return 0;
    }

    if (A==1 && B==1)                           /// Case 1
    {
        if (sA==1 && sB==0) FlipInput();

        if (n==3)
        {
            printf("-1\n");
            return 0;
        }

        GetComponents();

        for (int i = 1; i<=n; i++)
        {
            for (int j = i+1; j<=n; j++)
            {
                if ( !graph[i][j] )
                {
                    edges++;
                    mydegree[i]++;
                    mydegree[j]++;
                }
            }
        }

        ///Special case
        if ( L==2 && (compon[1].size()==1 || compon[2].size()==1) && edges==( (n-1)*(n-2)/2 ) )
        {
            if (compon[1].size()==1) isolated = compon[1][0];
            else isolated = compon[2][0];

            printf("2\n");

            if (isolated==1) spec = 2;
            else spec = 1;

            printf("%d %d\n",isolated,spec);

            if (isolated==2 || spec==2) printf("%d 3\n",spec);
            else printf("%d 2\n",spec);

            return 0;
        }

        mixed.clear();

        for (int i = 0; i<(int)compon[1].size(); i++)
        {
            mixed.push_back(compon[1][i]);
        }

        uk = 0;

        printf("%d\n",L-1);
        for (int i = 2; i<=L; i++)
        {
            while( mydegree[ mixed[uk] ] >= n-2 )
                uk++;

            printf("%d %d\n",mixed[uk],compon[i][0]);

            mydegree[ mixed[uk] ]++;
            mydegree[ compon[i][0] ]++;

            for (int j = 0; j<(int)compon[i].size(); j++)
            {
                mixed.push_back(compon[i][j]);
            }
        }
    }
    else
    {
        if (A==1 && B==0) FlipInput();

        DisconnG();

        printf("%d\n",(int)Ans.size());
        for (int i = 0; i<(int)Ans.size(); i++)
        {
            printf("%d %d\n",Ans[i].first,Ans[i].second);
        }
    }

    return 0;
}
