#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int a[100];

int minlen(int r1, int r2) {
    int ans = 100000;
    for(int i = min(r1, r2)-1; i < r1 || i < r2; ++i) {
        ans = min(ans, a[i]+1);
    }
    return ans;
}

int test(int r1, int c1, int r2, int c2) {
    int mid = c1;
    return abs(r1-r2) + abs(c2-min(c1, minlen(r1, r2)));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int ans = 100000;
    for(int r = 1; r <= n; ++r) {
        int pos = min(c1, minlen(r1, r));
        ans = min(ans, test(r1,c1,r,pos)+test(r,pos,r2,c2));
    }
    cout << ans << endl;
}
