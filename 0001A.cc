// CodeForce 1A.cc
#include <iostream>
using namespace std;


int main() {
    long long n = 0, m = 0, a = 0;
    cin >> n >> m >> a;
    cout << ((n - 1) / a + 1) * ((m - 1) / a + 1) << endl;
    return 0;
}