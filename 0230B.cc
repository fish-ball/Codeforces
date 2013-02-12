// The key point is to realize that the number should be a square of prime.


#include <iostream>
#include <algorithm>
#include <set> 
using namespace std;

typedef long long i64;

bool B[1000000] = {};

int main() {
   set<i64> primes2; 
   for(i64 i = 2; i < 1000000; ++i) {
       if(!B[i]) {
           primes2.insert(i * i); 
           for(i64 j = i * i; j < 1000000; j += i) {
               B[j] = true; 
           }
       } 
   }
   int n;
   i64 x; 
   for(cin >> n; n--;) {
       cin >> x;
       cout << (primes2.find(x) == primes2.end() ? "NO" : "YES") << endl;
   }  
   return 0; 
}