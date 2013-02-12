/*
  Simple implementation, small data scale, and a straight forward execution.
*/


#include <iostream>
#include <map>
using namespace std;

int main() {
   map<int, int> mp;
   int n, k;
   cin >> n >> k;
   for(int i = 0; i < n; ++i) {
       int tmp;
       cin >> tmp;
       if(tmp) ++mp[-tmp];
   }
   int count = 0;
   for(map<int, int>::iterator iter = mp.begin(); k > 0 && iter != mp.end(); ++iter) {
       count += iter->second;
       k -= iter->second;
   }
   cout << count << endl;
   return 0;
}