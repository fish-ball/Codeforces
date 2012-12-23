//   First, the order is insignificant, so sort them.
//   Then, enumerates the maximum number from 1 to the maximum overall.
// It was called O(maxnum) times, that is O(10^5).
//   For each i enumerates, find all its divisors, this requires O(sqrt(i))
// operations, that is O(sqrt(10^5)).
//   Then, for each divisor j, using binary search to find how many numbers
// that are greater than j, and store the numbers in array seg[] ascending.
//   Finally, you will know how to do, just see the code.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long i64;

i64 a[100000];
i64 MOD = 1000000007;
i64 xpow(i64 x, i64 n) {
    if(n == 0) return 1;
    if(x == 0) return 0;
    i64 y = xpow(x, n>>1);
    y *= y;
    y %= MOD;
    if(n & 1) {
        y *= x;
        y %= MOD;
    }
    return y;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    i64 ans = 0;
    vector<int> seg;
    for(i64 i = 1; i <= a[n-1]; ++i) {
        seg.clear();
        for(i64 j = 1; j * j <= i; ++j) {
            if(i % j == 0) {
                seg.push_back(a+n-lower_bound(a, a+n, j));
                if(j * j != i) {
                    seg.push_back(a+n-lower_bound(a, a+n, i/j));
                }
            }
        }
        sort(seg.rbegin(), seg.rend());
        i64 cnt = (xpow(seg.size(), seg.back()) - xpow(seg.size()-1, seg.back()) + MOD) % MOD;
        for(int i = seg.size()-2; i >= 0; --i) {
            cnt *= xpow(i+1, seg[i]-seg[i+1]);
            cnt %= MOD;
        }
        ans += cnt;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}