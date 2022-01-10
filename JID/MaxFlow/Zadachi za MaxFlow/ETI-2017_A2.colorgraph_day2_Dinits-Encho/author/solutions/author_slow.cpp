#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN=250;
int n;
int graph[MAXN+10][MAXN+10];
int A,B;

vector< pair<int,int> > Ans;
bool foundans=false;

vector< pair<int,int> > Changes;

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

    sA=true;
    sB=true;

    memset(TFO,false,sizeof(TFO));
    GetAll(1,0);

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            sA=false;
            break;
        }
    }

    memset(TFO,false,sizeof(TFO));
    GetAll(1,1);

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            sB=false;
            break;
        }
    }

    return;
}

void Batrak(int x,int y)
{
    if (x>n) ///Backtracking finished
    {
        GetState();

        if (sA==A && sB==B)
        {
            int i;

            Ans.clear();
            for (i=0;i<Changes.size();i++)
            {
                Ans.push_back(Changes[i]);
            }

            foundans=true;
        }
        return;
    }

    if (foundans && Ans.size()<=Changes.size()) ///We already have a better answer
    return;
    if (y>n)
    {
        Batrak(x+1,1);
        return;
    }
    if (y<=x)
    {
        Batrak(x,y+1);
        return;
    }

    ///Try not to change
    Batrak(x,y+1);

    ///Try to change
    graph[x][y]^=1;
    graph[y][x]^=1;
    Changes.push_back(make_pair(x,y));

    Batrak(x,y+1);

    Changes.pop_back();
    graph[x][y]^=1;
    graph[y][x]^=1;

    return;
}

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    scanf("%d %d",&A,&B);

    Batrak(1,1);

    if (!foundans)
    {
        printf("-1\n");
        return 0;
    }

    printf("%d\n",(int)Ans.size());
    for (i=0;i<Ans.size();i++)
    {
        printf("%d %d\n",Ans[i].first,Ans[i].second);
    }

    return 0;
}
