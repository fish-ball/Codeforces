/* 
  Sort the array first, then enumerate the maximum position j, then using binary 
search technology to find the maximum begin position r.
  We figure the sorted values be v[], and their accumulations be s[]. So if k is
enough to add all v[p:j] to v[j], there must be k >= v[j]*(j-p+1)-(s[j]-s[p]+v[j]).
  So find the position r = p, for p is valid while p-1 is invalid. Then the answer
should be max_val = v[j], max_count = j-p+1. Collect the optimal one for all j’s.
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long i64;

int main() {
   i64 n, k;
   cin >> n >> k;
   i64 v[100000] = {};
   i64 s[100000] = {};
   for(i64 i = 0; i < n; ++i) {
       cin >> v[i];
   }
   sort(v, v + n);
   for(i64 i = 1; i < n; ++i) {
       s[i] = s[i-1] + v[i-1];
   }
   i64 mxc = 0, mxp = n;
   for(int i = 0; i < n; ++i) {
       int j = n-1-i;
       int l = -1;
       int r = j;
       while(l + 1 < r) {
           int p = l+r+1 >> 1;
           if(k >= v[j]*(j-p+1)-(s[j]-s[p]+v[j])) {
               r = p;
           }
           else {
               l = p;
           }
       }
       if(mxc <= j-r+1) {
           mxc = j-r+1;
           mxp = v[j];
       }
   }
   cout << mxc << ' ' << mxp << endl;
    return 0;
}