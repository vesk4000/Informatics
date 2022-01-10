#include<iostream>
using namespace std;

const int N=100000;
int p[N+1];
int e[N+1];
int r[N+1], r1[N+1];
int p0[N+1], p1[N+1];

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

void mul(int p1[], int p2[], int r[])
{
  for(int i=1;i<=n;i++) r[i]=p2[p1[i]];
}

void pow (int p0[], long long int m, int r[])
{
	while (m>0)
    {
      if (m%2==1) {mul(r,p0,r1); cp(r1,r);}
      mul(p0,p0,p1);cp(p1,p0);
      m = m/2;
	}

}

int main()
{

 cin >> n >> m;
 for(int i=1;i<=n;i++) cin >> p[i];
 for(int i=1;i<=n;i++) e[i]=i;

 cp(e,r);
 cp(p,p0);
 pow(p0,m,r);
 perm(e,r,r1);
 show(r1);


}
