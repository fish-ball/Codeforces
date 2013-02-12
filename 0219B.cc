#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    long long p(0), d(0);
    cin >> p >> d;
    long long result = p;
    
    long long k(1);
    while((p + 1) % k <= d) {
        result = p - (p + 1) % k;
        k *= 10;
    }
    cout << result << endl;


    return 0;
}