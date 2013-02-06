// The key point is that only the species number matters.
// Then the answer is n minus the longest non-decreasing series len.

#include <algorithm>
#include <iostream>
using namespace std;


int main() {
    int n, m, a, b[5000], k = 0;
    double x;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a >> x;
        int p = upper_bound(b, b+k, a) - b;
        b[p] = a;
        if(p == k) ++k;
    }
    
    cout << n - k << endl;
}
