//   Pre-process an array cnt[], where cnt[i] means the count of the numbers which
// contains exactly i lucky numbers.
//   Then traverse the cnt[i] to be the Little Elephant Political Party's ballots,
// and using dfs to choose all the six remaining parties' ballots.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long i64;

i64 C[21][21] = {};
i64 cnt[10] = {-1}; 

int calc(int n, int k) {
    if(n == 0 || k < 0) return 0;
    vector<int> d;
    i64 ans = 0;
    while(n > 0) {
        d.push_back(n % 10);
        n /= 10;
    }
    for(int j = 0; j < d.back(); ++j) {
        if(j == 4 || j == 7) {
            if(k > 0) {
                ans += C[d.size()-1][k-1] * (1<<k-1) * (1<<3*(d.size()-k));
            }
        }
        else {
            ans += C[d.size()-1][k] * (1<<k) * (1<<3*(d.size()-1-k));
        }
    }
    for(int i = d.size()-1; i > 0; --i) {
        n *= 10;
        n += d[i-1];
    }
    if(d.back() == 4 || d.back() == 7) {
        ans += calc(n, k-1);
    }
    else {
        ans += calc(n, k);
    }
    return ans;
}

i64 dfs(i64 r, i64 k) {
    if(r == 0) return 1;
    i64 ans = 0;
    for(int i = 0; i <= k; ++i) {
        if(cnt[i] > 0) {
            --cnt[i];
            ans += (cnt[i]+1) * dfs(r-1, k-i);
            ans %= 1000000007;
            ++cnt[i];
        }
    }
    return ans;
}

int main() {
    for(int i = 0; i <= 20; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }
    
    int n;
    cin >> n;
    n += 1;
    for(int i = 0; i < 10; ++i) {
        cnt[i] += calc(n, i);
    }
    i64 ans = 0;
    for(int i = 1; i < 10 && cnt[i]; ++i) {
        ans += cnt[i] * dfs(6, i-1);
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}