#include<bits/stdc++.h>
#define MOD 1<<62
using namespace std;
typedef long long ll;
int n,m,k;
ll mem[32][32][32];
ll rec(int i,int j,int q)
{
    if(i==n) return 1;
    if(mem[i][j][q]>=0) return mem[i][j][q];
    int sum=0;
    for(int x=j+1;x<=m;x++) sum+=rec(i+1,x,1);
    if(q<k) sum+=rec(i+1,j,q+1);
    return mem[i][j][q]=sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    memset(mem,-1,sizeof(mem));
    cout<<rec(0,1,0)<<endl;
    //return main();
    return 0;
}
