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
    
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    if(xa > xb) swap(xa, xb);
    if(ya > yb) swap(ya, yb);
    
    pair<int, int> pt[4000];
    int m, n = 0;
    for(int y = ya; y <= yb; ++y) {
        pt[n++] = make_pair(xa, y);
        pt[n++] = make_pair(xb, y);
    }
    for(int x = xa+1; x < xb; ++x) {
        pt[n++] = make_pair(x, ya);
        pt[n++] = make_pair(x, yb);
    }
    int k;
    for(cin >> k; k--;) {
        int x, y, r;
        cin >> x >> y >> r;
        for(int i = m = 0; i < n; ++i) {
            if(     (pt[i].first-x)*(pt[i].first-x)+
                    (pt[i].second-y)*(pt[i].second-y) > r*r) {
                pt[m++] = pt[i];
            }
        }
        n = m;
    }
    cout << n;
    return 0;
}
