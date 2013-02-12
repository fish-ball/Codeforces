// Quite straight forward implementation.


#include <iostream>
using namespace std;

int gcd(int m, int n) {
   return n ? gcd(n, m%n) : m;
}

int main() {
   int a, b, n;
   cin >> a >> b >> n;
   int result = 1;
   while(n) {
       n -= result ? gcd(a, n) : gcd(b, n);
       result = 1 - result;
   }
   cout << result << endl;
   return 0;
}