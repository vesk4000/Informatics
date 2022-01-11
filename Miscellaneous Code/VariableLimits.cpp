#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cout << "short int:" << endl;
	cout << "	min: " << numeric_limits<short int>::min() << endl;
	cout << "	max: " << numeric_limits<short int>::max() << endl;
	cout << "int:" << endl;
	cout << "	min: " << numeric_limits<int>::min() << endl;
	cout << "	max: " << numeric_limits<int>::max() << endl;
	cout << "long int:" << endl;
	cout << "	min: " << numeric_limits<long int>::min() << endl;
	cout << "	max: " << numeric_limits<long int>::max() << endl;
	cout << "long long int:" << endl;
	cout << "	min: " << numeric_limits<long long int>::min() << endl;
	ostringstream convert;
	convert << numeric_limits<unsigned long long int>::max();
	cout << "	max: " << convert.str().size() << endl;
	return 0;
}
