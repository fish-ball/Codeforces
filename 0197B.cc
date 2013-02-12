/*
  Simple limit question of polynomial rationals, three main cases should be considered about.
*/


#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
   return b ? gcd(b, a%b) : a;
}

int main() {
   int n, m;
   cin >> n >> m;
   vector<int> a(n+1), b(m+1);
   for(int i = 0; i <= n; ++i) cin >> a[i];
   for(int i = 0; i <= m; ++i) cin >> b[i];

   if(n > m) {
       cout << (((a[0]>0)^(b[0]>0)) ? "-Infinity" : "Infinity") << endl;
   }
   else if(n < m) {
       cout << "0/1" << endl;
   }
   else {
       int aa = (a[0]>0?a[0]:-a[0]);
       int bb = (b[0]>0?b[0]:-b[0]);
       int _gcd = gcd(aa, bb);
       cout << (((a[0]>0)^(b[0]>0)) ? "-" : "") 
           << aa/_gcd << "/" << bb/_gcd << endl;
   }
   return 0;
}