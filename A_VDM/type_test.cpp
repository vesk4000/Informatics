#include <iostream>
#include <vector>
using namespace std;

int main() {
	bool b = true;
	uint8_t i = 5;
	uint8_t* ptr = (uint8_t*)&b;
	*ptr = 9;
	vector<bool> v;
	v.push_back(*ptr);
	vector<bool> v2(v);
	bool b2 = v[0];
	uint8_t* ptr2 = (uint8_t*)&(v2[0]);
	cout << (int)*ptr2 << endl;
	return 0;
}