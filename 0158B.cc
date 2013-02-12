/*
  Greedy: Count each group size, then pick from 4, 3, down to 1.
  The procedure can be easily understand by the code.
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int n, x, result = 0;
   int g[4] = {};
   cin >> n;
   for(int i = 0; i < n; ++i) {
       cin >> x;
       g[x-1]++;
   }
   cout << g[3] + g[2] + (g[1]+1)/2 +
           (max(g[0]-g[2]-g[1]%2*2, 0) + 3) / 4 
       << endl;
   return 0;
}