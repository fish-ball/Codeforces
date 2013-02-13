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
#include <cstring>
#include <ctime>
using namespace std;

typedef long long i64;

int main() {
    
    i64 n, a[100000];
    cin >> n;
    for(i64 i = 0; i < n; ++i) {
        cin >> a[i];
    }
    i64 m, w, h, pre = 0;
    cin >> m;
    for(i64 i = 0; i < m; ++i) {
        cin >> w >> h;
        pre = max(a[w-1], pre);
        cout << pre << endl;
        pre += h;
    }
    return 0;
}
