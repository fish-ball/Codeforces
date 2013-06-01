#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long i64;

//   C[l][r] stands for the minimum cost for sigle segment covers
// range(l..r), inclusive;
//   DP[i][j] stands for the cost when through range(0..i) inclusive,
// at least j holes covered.
i64 C[301][301] = {}, DP[301][301] = {};

int main() {

    int n, m, k;
    
    int l, r, c, i, j;
    
    cin >> n >> m >> k;
    
    memset(C, -1, sizeof(C));
    
    while(m--) {
        cin >> l >> r >> c;
        if(C[l-1][r-1] == -1 || C[l-1][r-1] > c) {
            C[l-1][r-1] = c;
        }
    }
    
    for(l = 0; l < n; ++l) {
        for(r = l+1; r < n; ++r) {
            for(i = l+1; i <= r; ++i) {
                if(C[i][r] == -1 || C[l][r] > -1 && C[i][r] > C[l][r]) {
                    C[i][r] = C[l][r];
                }
            }
        }
    }
    
    for(l = 0; l < n; ++l) {
        for(r = l+1; r < n; ++r) {
            for(i = l; i < r; ++i) {
                if(C[l][i] == -1 || C[l][r] > -1 && C[l][i] > C[l][r]) {
                    C[l][i] = C[l][r];
                }
            }
        }
    }
    
    memset(DP, -1, sizeof(DP));
    
    for(i = 0; i <= n; ++i) {
        DP[i][0] = 0;
        for(j = 1; j <= i; ++j) {
            if(DP[i][j] == -1 || DP[i][j-1] > -1 && DP[i][j] > DP[i][j-1]) {
                DP[i][j] = DP[i-1][j];
            }
            for(l = 1; j-l >= 0; ++l) {
                if(C[i-l][i-1] > -1 && DP[i-l][j-l] > -1) {
                    if(DP[i][j] == -1 || DP[i][j] > DP[i-l][j-l] + C[i-l][i-1]) {
                        DP[i][j] = DP[i-l][j-l] + C[i-l][i-1];
                    }
                }
            }
        }
    }
    
    i64 ans = -1;
    for(i = k; i <= n; ++i) {
        if(DP[n][i] != -1) {
            if(ans == -1 || ans > DP[n][i]) {
                ans = DP[n][i];
            }
        }
    }
    
    cout << ans << endl;

}
