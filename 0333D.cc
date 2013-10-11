#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;

int n, m;
int a[1000][1000];
bitset<1000> b[1000] = {};

int main() {
    
    scanf("%d%d", &n, &m);
    
    int i, j, k, ans = 0;
    
    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            scanf("%d", a[i]+j);
        }
    }
    
    for(i = 0; i < n; ++i) {
        for(j = i+1; j < n; ++j) {
            int x = 0, y = 0;
            for(k = 0; k < m; ++k) {
                if(a[i][k]>ans && a[j][k]>ans) {
                    x = max(x, min(a[i][k], a[j][k]));
                    if(x > y) swap(x, y);
                }
            }
            ans = max(ans, x);
        }
    }
    
    
    printf("%d\n", ans);
    
}
