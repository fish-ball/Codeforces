#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int dp[2][1001][1001];

int main() {
   int n, m, x, y;
   cin >> n >> m >> x >> y;
   string s;
   int count[1000] = {};
   for(int i = 0; i < n; ++i) {
       cin >> s;
       for(int j = 0; j < m; ++j) {
           count[j] += (s[j] == '#');
       }
   }
   memset(dp, -1, sizeof(dp));
   dp[0][0][0] = dp[1][0][0] = 0;
   for(int i = 0; i < m; ++i) {
       for(int d = 0; d < 2; ++d) {
           for(int j = x; j <= y; ++j) {
               if(dp[d][i][j] > -1 &&
                       (dp[1-d][i][0] == -1 || dp[1-d][i][0] > dp[d][i][j])) {
                   dp[1-d][i][0] = dp[d][i][j];
               }
           }
       }
       for(int d = 0; d < 2; ++d) {
           for(int j = 0; j < y; ++j) {
               if(dp[d][i][j] > -1 && 
                       (dp[d][i+1][j+1] == -1 || dp[d][i+1][j+1] > dp[d][i][j] + (d?count[i]:n-count))) {
                   dp[d][i+1][j+1] = dp[d][i][j] + (d?count[i]:n-count);
               }
           }
       }
   }
   int result = 0x7FFFFFFF;
   for(int j = x; j <= y; ++j) {
       if(dp[1][m][j] < result) result = dp[1][m][j];
       if(dp[0][m][j] < result) result = dp[0][m][j];
   }
   cout << result << endl;
   return 0;
}