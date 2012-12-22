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
#include <ctime>
#include <cstring>
using namespace std;

char c[400][401];
int a[401][401] = {};
int n, m, k;

int count_a(int x1, int y1, int x2, int y2) {
    return a[x2+1][y2+1]-a[x2+1][y1]-a[x1][y2+1]+a[x1][y1];
}

typedef long long i64;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    i64 ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%s", c[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            a[i+1][j+1] = c[i][j] == 'a';
            a[i+1][j+1] += a[i+1][j]+a[i][j+1]-a[i][j];
        }
    }
    vector<int> p;
    for(int x1 = 0; x1 < n; ++x1) {
        for(int x2 = x1+1; x2 < n; ++x2) {
            for(char d = 'a'; d <= 'z'; ++d) {
                p.clear();
                for(int y = 0; y < m; ++y) {
                    if(c[x1][y] == d && c[x2][y] == d) {
                        p.push_back(y);
                    }
                }
                for(i64 i = 0, j = 0; j < p.size(); ++j) {
                    while(i < j && count_a(x1, p[i], x2, p[j]) > k) ++i;
                    ans += j - i;
                }
            }
        }
    }
    printf("%I64d\n", ans);
}
