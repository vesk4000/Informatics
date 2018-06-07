#include <iostream>
#include <sstream>

using namespace std;

string convertToString(int n)
{
    ostringstream convert;
    convert << n;
    string result = convert.str();
    return result;
}

int main()
{
    int n;
    cin >> n;
    string ninString = convertToString(n);
    cout << ninString << " " << ninString.size() << endl;
    return 0;
}
