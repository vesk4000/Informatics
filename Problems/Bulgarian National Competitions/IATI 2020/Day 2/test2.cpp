#include <iostream>
#include <limits>
using namespace std;

int main() {
	int i = 0;
	cout << numeric_limits<int>::max() << endl;
	while(((long long int)1 << i) < numeric_limits<int>::max()) {
		cout << i << " " << ((long long int)1 << i) << endl;
		i++;
	}
	cout << i << " " << ((long long int)1 << i) << endl;
	return 0;
}
