#include <iostream>
using namespace std;

int main() {
	for(int i = 0; i < 100 * 100 * 100; ++i) {
		if(i % 5989 == 0)
			cout << 1 << endl;
	}
    return 0;
}
