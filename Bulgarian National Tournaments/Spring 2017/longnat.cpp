#include <iostream>

using namespace std;
int a[200000];
int dp[200000];
int maxValue;
int main()
{
    for(int i = 0;cin >> a[i]; ++i)
    {
        dp[i] = 1;
        for(int j = 0;j < i; ++j)
        {
            if(a[j] + 1 == a[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if(maxValue < dp[i])
            maxValue = dp[i];
    }
    /*int current = 0;
    while(cin>>a[i]) current++;
    for(int i = 0; i < current; ++i)
    {
        dp[a[i]] = dp[a[i]-1] + 1;
        if(dp[a[i]]>maxn) maxn = dp[a[i]];
    }
    cout << mxx << endl;*/
    cout << maxValue << endl;
    return 0;
}
