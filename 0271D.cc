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

int main() {
    
    string s, b;
    int k, n;
    int c[1501] = {};
    cin >> s >> b >> k;
    n = s.size();
    for(int i = 0; i < n; ++i) {
        if(b[s[i]-'a'] == '0') c[i+1] = c[i] + 1;
        else c[i+1] = c[i];
    }
    
    int ans = 0;
    
    for(int d = 1; d <= n; ++d) {
        set<string> st;
        for(int beg = 0, end; (end = beg + d) <= n; ++beg) {
            if(c[end] - c[beg] <= k) {
                st.insert(s.substr(beg, d));
            }
        }
        ans += st.size();
    }
    
    cout << ans << endl;
    
    return 0;
}
