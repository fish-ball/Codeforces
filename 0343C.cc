#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

int n, m;
    
i64 h[100000] = {};
i64 p[100000] = {};

bool test(i64 t) {
    for(int i = 0, j = 0; i < n; ++i) {
        if(h[i] - p[j] > t) return false;
        i64 v = min(h[i], p[j]);
        i64 w = max(h[i]+t-(h[i]-v)*2LL, h[i]+(t-h[i]+v)/2LL);
        j = upper_bound(p+j, p+m, w)-p;
        if(j == m) return true;
    }
    return false;
}

int main() {
    
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < n; ++i) scanf("%I64d", h+i);
    for(int i = 0; i < m; ++i) scanf("%I64d", p+i);
    
    i64 l = -1LL, r = 200000000000LL;
    
    while(l < r-1LL) {
        i64 md = l + r + 1LL >> 1LL;
        if(test(md)) r = md;
        else l = md;
    }
    
    printf("%I64d\n", r);
    
}
