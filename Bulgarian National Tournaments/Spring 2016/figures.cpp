#include <iostream>
#include <vector>

using namespace std;

struct point
{
    int row;
    int ninrow;
    int numbr;
};

point genPoint(int n)
{
    int row;
    int ninrow;
    point p;
    p.numbr = n;
    p.row = 1;
    p.ninrow = 0;
    for(int i = 0;i < n; ++i)
    {
        ++p.ninrow;
        if(p.ninrow > p.row)
        {
            ++p.row;
            p.ninrow = 1;
        }
    }
    return p;
}

int main()
{
    vector <point> pinp;
    int n;
    while(cin >> n)
    {
        pinp.push_back(genPoint(n));
        cout << genPoint(n).row << " " << genPoint(n).ninrow << endl;
    }

    if(pinp.size() == 3)
    {

    }
    return 0;
}
