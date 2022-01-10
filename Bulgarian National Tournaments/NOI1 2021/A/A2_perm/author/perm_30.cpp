#include<iostream>
using namespace std;

const int N=100000;
int p[N+1];
int a[N+1], b[N+1];
int e[N+1];

int n;
long long int m;

void cp(int a[], int b[])
{
  for(int i=1;i<=n;i++) b[i]=a[i];
}

void show(int a[])
{
 for(int i=1;i<=n;i++) cout << a[i]<<" ";
 cout << endl;
}

void perm(int a[], int p[], int b[])
{
 for(int i=1;i<=n;i++) b[p[i]]=a[i];
}


int main()
{

 cin >> n >> m;
 for(int i=1;i<=n;i++) cin >> p[i];
 for(int i=1;i<=n;i++) e[i]=i;

 cp(e,a);
 for(long long int j=1;j<=m;j++)
 {
   perm(a,p,b);
   cp(b,a);
 }
 show(b);
}
