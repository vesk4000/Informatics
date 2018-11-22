/// Sup guys
/// now you will understand how
/// to solve this BS problem
/// a.k.a. ThreeSum by Sashko Georgiev
/// more popular as
/// The Homosexual Man
/// Solution by Dmitriy LeeSin
/// a.k.a The Dick God
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 200000
#define endl '\n'
using namespace std;
int n;
long long d[4][MAXN];

/// d[1][i] gives the sum of the numbers [1, i]
/// d[2][i] gives the sum of the product of all couples from [1, i]
/// d[3][i] gives the sum of the product of all triplets from [1, i]

void find()
{
    cin >> n;

    d[1][1] = 1;
    d[2][1] = 1;
    d[3][1] = 1;
    
    /// easily initialize d[1]
    for (int i = 2; i <= n; i++) 
    {
        d[1][i] = d[1][i - 1] + i;
        d[1][i] %= MOD;
    }
    
    /// d[2][i] = sum of the product of all couples from (numbers from) [1, i - 1] combined with
    /// the product of all couples made of i and a number from [1, i - 1], which
    /// is equal to i * d[1][i]
    
    /// so d[2][i] = d[2][i - 1] + i * d[1][i]
    
    for (int i = 2; i <= n; i++) /// initialize d[2]
    {
        d[2][i] = d[2][i - 1] + i * d[1][i];
        d[2][i] %= MOD;
    }
    
    /// d[3][i] = sum of the product of all triplets from [1, i - 1] combined with
    /// the product of all triplets made of i and a couple made from [1, i], which
    /// is equal to i * d[2][i]
    
    /// so d[3][i] = d[3][i - 1] + i * d[2][i]
    
    for (int i = 2; i <= n; i++)
    {
        d[3][i] = d[3][i - 1] + i * d[2][i];
        d[3][i] %= MOD;
    }

    cout << d[3][n] << endl;
}

int main()
{
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    find();

    for (int i = 0; i < 69; i++) /// useless for loop cause
    ///                              action.informatika.bg language detection
    ///                              is BS and detects the code as Python 3
    ///                              for some reason

    return 0;
}
/// Hope you guys liked that
/// See you later
/// THE END