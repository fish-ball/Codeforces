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

vector<int> mp[5000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0, x; i < n+n; ++i) {
        scanf("%d", &x);
        mp[x-1].push_back(i+1);
    }
    bool yes = true;
    for(int i = 0; i < 5000; ++i) {
        if(mp[i].size() % 2) {
            yes = false;
            break;
        }
    }
    if(yes) {
        for(int i = 0; i < 5000; ++i) {
            for(int j = 0; j < mp[i].size(); j+=2) {
                printf("%d %d\n", mp[i][j], mp[i][j+1]);
            }
        }
    }
    else {
        printf("-1\n");
    }
    return 0;
}