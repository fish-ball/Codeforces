/*
  Grouping the sides into three groups, then check if on each layer the adjacent layer are in different group and the up/down group are always independently the same.
*/


#include <iostream>
using namespace std;

int main() {
   int group[] = {0, 1, 2, 3, 3, 2, 1};
   int n, x, a, b;
   cin >> n >> x;
   bool yes = true;
   while(n--) {
       cin >> a >> b;
       if(group[a] == group[b] ||
           group[b] == group[x] ||
           group[a] == group[x]) yes = false;
       x = 6 - group[a] - group[b];
   }
   cout << (yes ? "YES" : "NO") << endl;
   return 0;
}