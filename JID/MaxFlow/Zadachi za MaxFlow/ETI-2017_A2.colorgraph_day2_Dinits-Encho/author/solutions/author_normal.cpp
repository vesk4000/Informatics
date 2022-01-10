#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN=250;

int n;
int graph[MAXN+10][MAXN+10];
int A,B;

int sA,sB;
bool TFO[MAXN+10];

void GetAll(int ver,int color)
{
    int i;

    if (TFO[ver])
    return;

    TFO[ver]=true;

    for (i=1;i<=n;i++)
    {
        if (graph[ver][i]==color)
        GetAll(i,color);
    }

    return;
}

void GetState()
{
    int i,j;

    sA=1;
    sB=1;

    memset(TFO,false,sizeof(TFO));
    GetAll(1,0);

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            sA=0;
            break;
        }
    }

    memset(TFO,false,sizeof(TFO));
    GetAll(1,1);

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            sB=0;
            break;
        }
    }

    return;
}

///1 1
int L=0;
vector<int> components[MAXN+10];

void DFS(int ver,int c)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;
    components[c].push_back(ver);

    int i;

    for (i=1;i<=n;i++)
    {
        if (graph[ver][i]==0)
        DFS(i,c);
    }

    return;
}

void GetComponents()
{
    int i;

    memset(TFO,false,sizeof(TFO));

    for (i=1;i<=n;i++)
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

bool GetPath(int ver)
{
    if (TFO[ver])
    return false;

    TFO[ver]=true;
    Path.push_back(ver);

    if (ver==TARGET)
    return true;

    int i;

    for (i=1;i<=n;i++)
    {
        if (flow[ver][i]<cap[ver][i])
        {
            if (GetPath(i))
            return true;
        }
    }

    Path.pop_back();

    return false;
}

void Reachables(int ver)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;

    int i;

    for (i=1;i<=n;i++)
    {
        if (flow[ver][i]<cap[ver][i])
        Reachables(i);
    }

    return;
}

vector< pair<int,int> > Ans;
bool hasans=false;

vector< pair<int,int> > Changes;

void GetCut()
{
    int i,j;

    memset(TFO,false,sizeof(TFO));
    Reachables(SOURCE);

    Changes.clear();
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
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

        for (i=0;i<Changes.size();i++)
        {
            Ans.push_back(Changes[i]);
        }

        hasans=true;
    }

    return;
}

void SendFlow()
{
    int i;

    for (i=1;i<Path.size();i++)
    {
        flow[ Path[i-1] ][ Path[i] ]++;
        flow[ Path[i] ][ Path[i-1] ]--;
    }

    return;
}

void GetMinCut() ///Ford-Fulkerson
{
    memset(TFO,false,sizeof(TFO));
    Path.clear();
    while(GetPath(SOURCE))
    {
        SendFlow();
        Path.clear();
        memset(TFO,false,sizeof(TFO));
    }

    GetCut();

    return;
}

void DisconnectGraph()
{
    int i,j;

    for (i=1;i<=n;i++)
    {
        cap[i][i]=0;
        for (j=i+1;j<=n;j++)
        {
            if (graph[i][j]==0)
            {
                cap[i][j]=1;
                cap[j][i]=1;
            }
            else
            {
                cap[i][j]=0;
                cap[j][i]=0;
            }
        }
    }

    SOURCE=1;

    for (i=2;i<=n;i++) ///Separate 1 from i
    {
        memset(flow,0,sizeof(flow));
        TARGET=i;

        GetMinCut();
    }

    return;
}

///
void FlipInput()
{
    int i,j;
    int swp;

    swp=A;
    A=B;
    B=swp;

    swp=sA;
    sA=sB;
    sB=swp;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            graph[i][j]^=1;
        }
    }

    return;
}

vector<int> mixed;
int mydegree[MAXN+10];

int main()
{
    int i,j;
    int isolated,spec;
    int edges=0;
    int sum=0;
    int uk;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        sum=0;
        for (j=1;j<=n;j++)
        {
            scanf("%d",&graph[i][j]);
            sum+=graph[i][j];
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

    if (A==1 && B==1) ///Case 1
    {
        if (sA==1 && sB==0)
        {
            FlipInput();
        }

        if (n==3)
        {
            printf("-1\n");
            return 0;
        }

        GetComponents();

        for (i=1;i<=n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                if (graph[i][j]==0)
                {
                    edges++;
                    mydegree[i]++;
                    mydegree[j]++;
                }
            }
        }

        ///Special case
        if ( L==2 && (components[1].size()==1 || components[2].size()==1) && edges==( (n-1)*(n-2)/2 ) )
        {
            if (components[1].size()==1)
            isolated=components[1][0];
            else
            isolated=components[2][0];

            printf("2\n");

            if (isolated==1)
            spec=2;
            else
            spec=1;

            printf("%d %d\n",isolated,spec);

            if (isolated==2 || spec==2)
            printf("%d 3\n",spec);
            else
            printf("%d 2\n",spec);

            return 0;
        }

        mixed.clear();
        for (i=0;i<components[1].size();i++)
        {
            mixed.push_back(components[1][i]);
        }

        uk=0;

        printf("%d\n",L-1);
        for (i=2;i<=L;i++)
        {
            while(mydegree[ mixed[uk] ]>=n-2)
            uk++;

            printf("%d %d\n",mixed[uk],components[i][0]);

            mydegree[ mixed[uk] ]++;
            mydegree[ components[i][0] ]++;

            for (j=0;j<components[i].size();j++)
            {
                mixed.push_back(components[i][j]);
            }
        }
    }
    else
    {
        if (A==1 && B==0)
        {
            FlipInput();
        }

        DisconnectGraph();

        printf("%d\n",(int)Ans.size());
        for (i=0;i<Ans.size();i++)
        {
            printf("%d %d\n",Ans[i].first,Ans[i].second);
        }
    }

    return 0;
}
