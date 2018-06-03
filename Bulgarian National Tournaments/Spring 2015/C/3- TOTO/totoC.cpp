#include <iostream>
#include <algorithm>
using namespace std;

const int n=6;

bool adj[50][50]; // матрица на съседство

int row(int x)
{ return 1+(x-1)/7; }

int col(int x)
{ return 1+(x-1)%7; }

void init() // инициализиране матрицата на съседство
{ for(int x=1; x<50; x++)
    for(int y=x+1; y<50; y++)
    { int i1=row(x), j1=col(x);
      int i2=row(y), j2=col(y);
      int p=abs(i1-i2), q=abs(j1-j2);
      adj[x][y] = adj[y][x] = ((p==2 && q==1)||(p==1 && q==2));
    }
}

bool loop(int a[]) // проверка за цикъл
{ for(int i=0; i<n; i++)
    if(!adj[a[i]][a[(i+1)%n]]) return false;
  return true;
}

bool ok(int a[])
{
  for(int i=0; i<n; i++)
  { int br=0;
    for(int j=0; j<n; j++)
      if(adj[a[i]][a[j]]) br++;
    if(br<2) return false; // всеки връх трябва има
                           // поне два съседни
  }

  do
  { if(loop(a)) return true;}
  while(next_permutation(a+1,a+n));
  return false;
}

int main()
{ init();

  int k; cin >> k;
  int cnt=0;
  int b[6],c[6];
  for(c[0]=1;      c[0]<50;  c[0]++)
  for(c[1]=c[0]+1; c[1]<50; c[1]++)
  for(c[2]=c[1]+1; c[2]<50; c[2]++)
  for(c[3]=c[2]+1; c[3]<50; c[3]++)
  for(c[4]=c[3]+1; c[4]<50; c[4]++)
  for(c[5]=c[4]+1; c[5]<50; c[5]++)
  { for(int j=0; j<6; j++) b[j]=c[j];
    if(ok(b))
    { cnt++;
      if(cnt==k)
      { for(int i=0; i<5; i++)
          cout << c[i] << " ";
        cout << c[5] << endl;
        return 0;
      }
    }
  }

  return 0;
}
