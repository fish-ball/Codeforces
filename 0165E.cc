#include <cstdio>
#include <cstring>
#include <cstdlib>

int n, mask = (1<<22)-1;
int a[1<<22], dp[1<<22];
int q[1<<22], k = 0;

int main() {
    
    memset(dp, -1, sizeof(dp));
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        if(dp[mask^a[i]] == -1) {
            dp[mask^a[i]] = a[i];
            q[k++] = mask^a[i];
        }
    }
    
    while(k) {
        int x = q[--k], y;
        for(int i = 1; i < mask; i<<=1) {
            if(x&i) {
                y = x^i;
                if(dp[y] == -1) {
                    dp[y] = dp[x];
                    q[k++] = y;
                }
            }
        }
    }
    
    for(int i = 0; i < n; ++i) {
        if(i) putchar(' ');
        printf("%d", dp[a[i]]);
    }
    puts("");
    
}
