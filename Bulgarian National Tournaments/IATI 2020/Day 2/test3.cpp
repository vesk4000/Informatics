#include <iostream>
#include <limits>
using namespace std;

const long long int mult = numeric_limits<int>::max();

long long int coords2num(pair<int, int> coords) {
	return coords.first * mult + coords.second;
}

long long int coords2num(int x, int y) {
	return coords2num({x, y});
}

pair<int, int> num2coords(long long int num) {
	return {num / mult, num % mult};
}

int main() {
	//cout << 1374389534720 / (1 << 32) << endl;
	while(true) {
		int x, y;
		cin >> x >> y;
		long long int num = coords2num(x, y);
		cout << num << " " << num2coords(num).first << " " << num2coords(num).second << endl;
	}
	return 0;
}
