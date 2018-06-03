//Task: lg
//Author: Kinka Kirilova-Lupanova

#include <stdio.h>
#include <string.h>
using namespace std;
int a[102],t[102];

bool lesseq(int a[], int b[])
{int i;
 for (i=101;i>=0;i--) 
    {if (a[i]<b[i]) return true; 
     if (a[i]>b[i]) return false; 
    }
 return true;
}

void  mullong(int a[], int b)
{int  i;
 for (i=0; i<102;i++) 
    a[i]=a[i]*b;
 for (i=0; i<101;i++) 
    {a[i+1]=a[i+1]+a[i] / 10;
     a[i]=a[i] % 10;
    }
}

int main()
{
	char s[102];
	int n,b,ans=0,i,head;

	scanf("%s%d",s,&b);
	n=strlen(s);
	for (i=0;i<n;i++)
		a[n-1-i]=s[i]-'0';
	t[0]=1;
    while (lesseq(t,a)) 
          {mullong(t,b);
           ans++;
          } 
	printf("%d\n",ans-1);
	return 0;
}

