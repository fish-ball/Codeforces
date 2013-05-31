#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int acc[100000] = {};
    for(int i = 1; i < s.size(); ++i) {
        acc[i] = acc[i-1] + (s[i] == s[i-1] ? 1 : 0);
    }
    int n;
    for(cin >> n; n--;) {
        int l, r;
        cin >> l >> r;
        cout << acc[r-1] - acc[l-1] << endl;
    }
    return 0;
}
