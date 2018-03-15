#include <iostream>

using namespace std;

void cswap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int main(){
	int a, b;
	cin >> a >> b;
	cswap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}
