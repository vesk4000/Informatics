#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
int graph[1111][1111];
int A,B;
int minchanges;

int changes;

int sA,sB;
bool TFO[1111];

void Go(int ver,int color)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;

    int i;

    for (i=1;i<=n;i++)
    {
        if (graph[ver][i]==color)
        Go(i,color);
    }

    return;
}

void GetState()
{
    int i,j;

    memset(TFO,false,sizeof(TFO));
    Go(1,0);

    sA=1;
    for (i=2;i<=n;i++)
    {
        if (!TFO[i])
        sA=0;
    }

    memset(TFO,false,sizeof(TFO));
    Go(1,1);

    sB=1;
    for (i=2;i<=n;i++)
    {
        if (!TFO[i])
        sB=0;
    }

    return;
}

int main(int argc, char *argv[])
{
    int i,j;
    int a,b;

    FILE *in = fopen(argv[1], "r");

    if (!in)
    {
        fprintf(stderr,"In-file %s not found\n",argv[1]);
        printf("0\n");
        return 0;
    }

    fscanf(in, "%d", &n);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            fscanf(in, "%d",&graph[i][j]);
        }
    }

    fscanf(in, "%d %d",&A,&B);

    fclose(in);

    FILE *sol = fopen(argv[2],"r");

    if (!sol)
    {
        fprintf(stderr,"Sol-file %s not found\n",argv[2]);
        printf("0\n");
        return 0;
    }

    fscanf(sol, "%d", &minchanges);

    fclose(sol);

    FILE *out = fopen(argv[3], "r");

    if (!out)
    {
        fprintf(stderr,"Out-file %s not found\n",argv[3]);
        printf("0\n");
        return 0;
    }

    fscanf(out, "%d",&changes);

    if (changes!=minchanges)
    {
        fprintf(stderr,"Wrong answer: incorrect number of changes!\n");
        printf("0\n");
        return 0;
    }

    if (changes==-1)
    {
        fprintf(stderr,"Correct!\n");
        printf("1\n");

        return 0;
    }

    for (i=1;i<=changes;i++)
    {
        fscanf(out,"%d %d",&a,&b);

        if (a<1 || b<1 || a>n || b>n || a==b)
        {
            fprintf(stderr,"Wrong answer: invalid edge!\n");
            printf("0\n");
            return 0;
        }

        graph[a][b]^=1;
        graph[b][a]^=1;
    }

    fclose(out);

    GetState();

    if (sA!=A || sB!=B)
    {
        fprintf(stderr,"Wrong answer: incorrect final state!\n");
        printf("0\n");
        return 0;
    }

    fprintf(stderr, "Correct!\n");
    printf("1\n");

    return 0;
}
