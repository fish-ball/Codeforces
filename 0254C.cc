// Greedy..
// Problem: http://codeforces.com/problemset/problem/254/C

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string a, b;
    cin >> a >> b;
    int d[26] = {}, c[26] = {};
    int n = a.size();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ++c[a[i]-'A'];
        ++d[a[i]-'A'];
        --d[b[i]-'A'];
    }
    for(int i = 0; i < 26; ++i) {
        ans += max(d[i], 0);
    }
    cout << ans << endl;
    int k = 0;
    for(int i = 0; i < n; ++i) {
        while(k < 26 && d[k] >= 0) ++k;
        if(d[a[i]-'A'] > 0 && (a[i]-'A' > k || c[a[i]-'A'] == d[a[i]-'A'])) {
            --d[a[i]-'A'];
            --c[a[i]-'A'];
            ++d[k];
            a[i] = 'A' + k;
        }
        else {
            --c[a[i]-'A'];
        }
    }
    cout << a << endl;
    return 0;
}