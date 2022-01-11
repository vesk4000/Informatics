#include <iostream>
#include <math.h>
using namespace std;

long long int n;
int t;
long long int MOD = 1e9 + 7;

long long int powc(int num, long long int power) {
    long long int ans = 1;
    for(long long int i = 0; i < power; ++i)
        ans = (ans * num) % MOD;
    return ans;
}

long long int mode0 = 1;
long long int mode02;
long long int mode1;
long long int mode2;

long long int new_mode0;
long long int new_mode02;
long long int new_mode1;
long long int new_mode2;

int main() {
    cin >> n >> t;

    if(t == 1) { /// Rectangle
        long long int power = ceil(n / 2.0);
        cout << powc(2, power) << endl;
    }
    else if(t == 2) { /// Square
        long long int power = n / 3;
        cout << powc(2, power) << endl;
    }
    else if(t == 3) { /// Both
        for(long long int i = 0; i < n; ++i) {
            new_mode1 = mode2 + mode0;
            new_mode2 = mode1 + mode0;
            new_mode0 = mode02 + mode0;
            new_mode02 = mode1 + mode2 + mode0;

            mode1 = new_mode1 % MOD;
            mode2 = new_mode2 % MOD;
            mode0 = new_mode0 % MOD;
            mode02 = new_mode02 % MOD;
        }
        cout << mode0 << endl;
    }

    return 0;
}
