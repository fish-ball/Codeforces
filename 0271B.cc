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

bool B[100100] = {};
vector<int> P;

typedef long long i64;

int main() {
    
    for(i64 i = 2; i < 100100; ++i) {
        if(!B[i]) {
            P.push_back(i);
            for(i64 j = i * i; j < 100100; j += i) {
                B[j] = true;
            }
        }
    }
    
    int row[500] = {}, col[500] = {};
    
    int n, m, x, y;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> x;
            y = *lower_bound(P.begin(), P.end(), x);
            row[i] += y - x;
            col[j] += y - x;
        }
    }
    
    int ans = 0x7FFFFFFF;
    for(int i = 0; i < n; ++i) ans = min(ans, row[i]);
    for(int i = 0; i < m; ++i) ans = min(ans, col[i]);
    
    cout << ans << endl;

    return 0;
}
