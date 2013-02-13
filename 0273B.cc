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
    
    int n, m;
    cin >> n;
    
    map<int, vector<int> > mp;
    
    for(int i = 0, x; i < n + n; ++i) {
        cin >> x;
        mp[x].push_back(i % n);
    }
    
    cin >> m;
    
    i64 ans = 1;
    
    for(map<int, vector<int> >::iterator it1 = mp.begin(); it1 != mp.end(); ++it1) {
        vector<int> &v = it1->second;
        int c1 = v.size(), c2 = 0;
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); ++i) {
            if(v[i] == v[i-1]) ++c2;
        }
        for(int i = 2, k; (k = i) <= c1; ++i) {
            while(c2 > 0 && k % 2 == 0) {
                --c2;
                k >>= 1;
            }
            ans *= k;
            ans %= m;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
