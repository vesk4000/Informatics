/*
ID: espr1t
TASK: Closest Number
KEYWORDS: Testgen & Solver
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cassert>

using namespace std;

const long long MAX_VAL = 1000000000000000000LL;
const long long LIM = MAX_VAL * 2LL;

unsigned sTime;
long long ans, needle;
vector <int> nums({2, 3, 5, 7, 11, 13, 17, 19});

void recurse(long long cur, int dig) {
    if (abs(needle - ans) > abs(needle - cur))
        ans = cur;
    else if (abs(needle - ans) == abs(needle - cur))
        ans = min(ans, cur);
    if (cur >= needle || dig >= (int)nums.size() || LIM / nums[dig] < cur)
        return;
    recurse(cur * nums[dig], dig);
    recurse(cur, dig + 1);
}

long long eval(long long findWhat) {
    fprintf(stderr, "  -- eval %lld\n", findWhat);
    ans = 1;
    needle = findWhat;
    recurse(1, 0);
    return ans;
}

int cntr;
bool go2(long long cur, int last) {
    if (++cntr % 100000 == 0) {
        if ((double)(clock() - sTime) / CLOCKS_PER_SEC > 1.0) {
            return false;
        }
    }
    
    if (abs(needle - ans) > abs(needle - cur))
        ans = cur;
    else if (abs(needle - ans) == abs(needle - cur))
        ans = min(ans, cur);
    if (cur >= needle)
        return true;
    for (int i = last; i <= 20 && LIM / i >= cur; i++) {
        if (!go2(cur * i, i))
            return false;
    }
    return true;
}

bool go1(long long cur) {
    if (++cntr % 100000 == 0) {
        if ((double)(clock() - sTime) / CLOCKS_PER_SEC > 1.0) {
            return false;
        }
    }

    if (abs(needle - ans) > abs(needle - cur))
        ans = cur;
    else if (abs(needle - ans) == abs(needle - cur))
        ans = min(ans, cur);
    if (cur >= needle)
        return true;
    for (int i = 0; i < (int)nums.size() && LIM / nums[i] >= cur; i++) {
        if (!go1(cur * nums[i]))
            return false;
    }
    return true;
}

long long dummy(long long findWhat) {
    cntr = 0;
    ans = 1;
    needle = findWhat;
    go2(1, 2);
    return ans;
}

void solve(long long num1, long long num2, int testNum, FILE* sol) {
    fprintf(stderr, "Solving testcase %d...\n", testNum);
    sTime = clock();
    fprintf(sol, "%lld %lld\n", eval(num1), eval(num2));
    fprintf(stderr, "  -- author's execution time: %.3lfs\n",
        (double)(clock() - sTime) / CLOCKS_PER_SEC);
    
    /*
    sTime = clock();
    bool succeeded = dummy(num1);
    if (succeeded)
        succeeded = dummy(num2);
    fprintf(stderr, "  -- dummy execution time: %.3lfs\n",
        (double)(clock() - sTime) / CLOCKS_PER_SEC);
    */
}

int main(void) {
    vector <long long> tests;
    vector < pair <long long, long long> > wholeTests;
    
    // Examples
    tests.push_back(404);
    tests.push_back(42);
    tests.clear();
    tests.push_back(213);
    /*
    Here both 210 and 216 can be expressed as 14 * 15 and 8 * 3 * 9, respectively. No number between
    them can be expressed as a product of numbers between 1 and 20, inclusive. Since both of them
    are equally distanced from the target number, we chose the smaller one.
    */
    tests.push_back(3583285984563497LL);
    wholeTests.push_back(make_pair(tests[0], tests[1]));
    
    tests.clear();

    tests.push_back(1);
    tests.push_back(666);
    tests.push_back(1337);
    tests.push_back(123456789);

    tests.push_back(MAX_VAL);
    tests.push_back(952262371856596500LL);
    tests.push_back(9876543210LL);
    tests.push_back(987654321123456789LL);
    tests.push_back(30101125978245452LL);

    long long add;

    // All represented
    add = 1;
    for (int i = 0; MAX_VAL / nums[i % (int)nums.size()] >= add; i++)
        add *= nums[i % (int)nums.size()];
    tests.push_back(add);


    // Random factors
    for (int i = 0; i < 5; i++) {
        add = 1;
        for (int i = 0; i < 20; i++) {
            int idx = rand() % (int)nums.size();
            if (MAX_VAL / nums[idx] >= add)
                add *= nums[idx];
        }
        tests.push_back(add);
    }
    
    // One very represented, rest random
    for (int i = 0; i < 5; i++) {
        add = 1;
        int idx = rand() % (int)nums.size();
        while ((MAX_VAL / 10000) / nums[idx] >= add)
            add *= nums[idx];
        for (int i = 0; i < 20; i++) {
            idx = rand() % (int)nums.size();
            if (MAX_VAL / nums[idx] >= add)
                add *= nums[idx];
        }
        tests.push_back(add);
    }
    
    // Two very represented
    for (int i = 0; i < 5; i++) {
        int idx[2] = {rand() % (int)nums.size(), rand() % (int)nums.size()};
        add = 1;
        for (int c = 0; c < 100; c++) {
            if (MAX_VAL / nums[idx[c % 2]] >= add)
                add *= nums[idx[c % 2]];
        }
        tests.push_back(add);
    }    
    
    for (int i = 0; i < 5; i++) {
        tests.push_back(tests[(int)tests.size() - 50] + 10 - rand() % 20);
        if (tests.back() < 1) tests.back() = rand() % 100 + 1;
        if (tests.back() > MAX_VAL) tests.back() = MAX_VAL - rand() % 100;
    }
    
    for (int i = 0; i < 5; i++) {
        tests.push_back(rand() % 1000 + 10);
    }
    
    for (int i = 0; i < 5; i++) {
        tests.push_back(MAX_VAL - rand() % 10000 - 10);
    }

    fprintf(stderr, "Number of single tests = %d\n", (int)tests.size());
    assert((int)tests.size() == 40);

    random_shuffle(tests.begin(), tests.end());
    
    for (int i = 0; i < (int)tests.size(); i += 2) {
        wholeTests.push_back(make_pair(tests[i], tests[i + 1]));
    }
    
    for (int test = 0; test < (int)wholeTests.size(); test++) {
        char inpFile[32], solFile[32];
        sprintf(inpFile, "ClosestNumber.%02d.in", test);
        sprintf(solFile, "ClosestNumber.%02d.sol", test);
        
        FILE* in = fopen(inpFile, "wt");
        fprintf(in, "%lld %lld\n", wholeTests[test].first, wholeTests[test].second);
        fclose(in);
        
        FILE* sol = fopen(solFile, "wt");
        solve(wholeTests[test].first, wholeTests[test].second, test, sol);
        fclose(sol);
    }
    return 0;
}
