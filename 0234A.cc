// Construct the answer, pairing the i-th and the (i+n/2)-th student.
// What we should do is to decide whether to swap their position.
// Answer is, only when i-th is R while (i+n/2) is L.


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int n;
   string s;
   cin >> n >> s;
   for(int i = 0; i < n / 2; ++i) {
       if(s[i] == 'R' && s[i+n/2] == 'L')
           cout << n/2+1+i << ' ' << 1+i << endl;
       else
           cout << i+1 << ' ' << n/2+1+i << endl;
   }
   return 0;
}