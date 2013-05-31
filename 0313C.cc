#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    for(int w = n; w > 0; w >>= 2) {
        for(int i = 0; i < w; ++i) {
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
