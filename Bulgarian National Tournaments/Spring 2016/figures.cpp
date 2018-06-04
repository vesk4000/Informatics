#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 32768;

bool used[maxn];

struct point
{
    int row;
    int ninrow;
    int numbr;
};

bool cmp(point& a, point& b)
{
	return a.numbr < b.numbr;
}

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

int tri(vector <point> pinp)
{
	if(pinp[1].row == pinp[2].row)
		{
			int ans = abs(pinp[0].row - pinp[1].row);
			if(ans == abs(pinp[1].ninrow - pinp[2].ninrow))
			{
				return ans;
			}
			else
			{
				return -1;
			}
		}
		else if(pinp[0].row == pinp[1].row)
		{
			int ans = abs(pinp[1].row - pinp[2].row);
			if(ans == abs(pinp[0].ninrow - pinp[1].ninrow))
			{
				return ans;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
}

int main()
{
    vector <point> pinp;
    int n;
    while(cin >> n)
    {
        pinp.push_back(genPoint(n));
		//cout << genPoint(n).row << " " << genPoint(n).ninrow << endl;
    }

	sort(pinp.begin(), pinp.end(), cmp);

    if(pinp.size() == 3)
    {
    	int ans = tri(pinp);
    	if(ans != -1)
			cout << "T " << tri(pinp) << endl;
		else
			cout << "INCORRECT" << endl;
    	return 0;
    }
    if(pinp.size() == 4)
    {
    	if(pinp[3].ninrow < pinp[1].ninrow)
		{
			vector <point> t;
			t.push_back(pinp[0]);
			t.push_back(pinp[2]);
			t.push_back(pinp[3]);
			int ans = tri(t);
			vector <point> t1;
			t1.push_back(pinp[0]);
			t1.push_back(pinp[1]);
			t1.push_back(pinp[3]);
			int ans1 = tri(t1);
			if(ans == ans1 && ans != -1)
			{
				cout << "R " << ans << endl;
				return 0;
			}
			else
			{
				cout << "INCORRECT" << endl;
				return 0;
			}
		}
		else
		{
			vector <point> t;
			t.push_back(pinp[0]);
			t.push_back(pinp[1]);
			t.push_back(pinp[3]);
			int ans = tri(t);
			vector <point> t1;
			t1.push_back(pinp[1]);
			t1.push_back(pinp[2]);
			t1.push_back(pinp[3]);
			int ans1 = tri(t1);
			if(ans == ans1 && ans != -1)
			{
				cout << "R " << ans << endl;
				return 0;
			}
			else
			{
				cout << "INCORRECT" << endl;
				return 0;
			}
		}
    }
    if(pinp.size() == 6)
	{
		if(pinp[0].row == pinp[1].row)
		{

		}
	}
    cout << "INCORRECT" << endl;
    return 0;
}
