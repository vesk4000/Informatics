#include <iostream>

using namespace std;

struct aStruct/// Declare a struct
{
	int foo;
	int bar;
};

int main()
{
	int a;///declare variable
	a = 5;///set the value of a
	cout << a << endl;///the value of a
	cout << &a << endl;///the address of a

	int *p;///declare a pointer
	p = &a;///set the value of p to the address of a
	cout << p << endl;///the address stored in p(a)
	cout << *p << endl;///the value stored at the address stored in p

	aStruct s;///Create an object s of aStruct
	aStruct *ps;///Create a pointer for aStruct
	ps = &s;///set the value of ps to the address of s
	s.foo = 1;///set the value of s.foo
	s.bar = 2;///set the value of s.bar
	cout << ps << endl;///the address of s
	cout << (*ps).foo << endl;///the value stored in the address stored in ps
	cout << (*ps).bar << endl;
	return 0;
}
