#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// 1. Dynamic Programming: define the status arrays.
// 1.1. mchg[i][j] figures the minimum changes 
//      before s[i] to keep 'A'+j.
int mchg[26][500001] = {};
// 1.2. prev[i][j] figures the preview charactor when optimized.
int prev[26][500001] = {};


int main() {
    int n(0), k(0);
    string s("");
    cin >> n >> k >> s;
    
    // 2. The initial state.
    for(int i = 0; i < k; ++i) {
        mchg[i][0] = s[0] == 'A' + i ? 0 : 1;
    }
    for(int j = 1; j < s.size(); ++j) {
        for(int i = 0; i < k; ++i) {
            int add = s[j] == 'A' + i ? 0 : 1;
            int pos = -1, val = n + 1;
            for(int p = 0; p < k; ++p) {
                if(p != i && mchg[p][j-1] < val) {
                    pos = p; 
                    val = mchg[p][j-1];
                }
            }
            mchg[i][j] = val + add;
            prev[i][j] = pos;
        }
    }
    int res_pos(-1), result(n+1);
    for(int i = 0; i < k; ++i) {
        if(mchg[i][n-1] < result) {
            res_pos = i;
            result = mchg[i][n-1];
        }
    }
    s[n-1] = 'A' + res_pos;
    for(int j = n - 1; j > 0; --j) {
        s[j-1] = 'A' + prev[res_pos][j];
        res_pos = prev[res_pos][j];
    }
    
    cout << result << endl;
    cout << s << endl;
    
    return 0;
}