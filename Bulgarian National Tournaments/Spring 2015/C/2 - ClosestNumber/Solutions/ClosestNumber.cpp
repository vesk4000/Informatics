/*
ID: espr1t
TASK: Closest Number
KEYWORDS: Easy, Bruteforce, Simple Math (Primes)
*/

#include <iostream>
#include <algorithm>

using namespace std;

const long long LIM = 1000000000000000000LL;

long long ans, needle;
vector <int> nums({2, 3, 5, 7, 11, 13, 17, 19});

void recurse(long long cur, int dig)
{
    if (cur >= needle || dig >= (int)nums.size() || LIM / nums[dig] < cur)
    {
        if (abs(needle - ans) > abs(needle - cur))
            ans = cur;
        else if (abs(needle - ans) == abs(needle - cur))
            ans = min(ans, cur);
        return;
    }
    recurse(cur * nums[dig], dig);
    recurse(cur, dig + 1);
}

int main(void)
{
//    freopen("ClosestNumber.in", "rt", stdin);

    cin >> needle;
    ans = 1;
    recurse(1, 0);
    cout << ans << " ";
    cin >> needle;
    ans = 1;
    recurse(1, 0);
    cout << ans << endl;

    return 0;
}
