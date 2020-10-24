#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cout << rand(59) % 1000000 << endl;
	}
	return 0;
}