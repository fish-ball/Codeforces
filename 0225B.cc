/*
 Here a greedy strategy works.
 First generate all the K-Fibonacci numbers, there will be no more than log2(s) numbers in the set.
 Then enumerates all the numbers vals[i] from bigger to smaller, and choose if it is smaller than the remaining value.
 The key point is that when we consider about vals[i], the vals[i] is always greater or equals the sum of the remaining numbers.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long i64;

int main() {
   i64 s, k;
   cin >> s >> k;

   vector<i64> vals(1, 1);
   i64 sum = 1;
   for(i64 i = 1; i < k && vals.back() < s; ++i) {
       vals.push_back(1LL<<i);
       sum += (1LL<<i);
   }
   while(vals.size() >= k && sum <= s) {
       vals.push_back(sum);
       sum -= vals[vals.size() - k - 1];
       sum += vals.back();
   }

   vector<i64> ans(0);
   for(int i = vals.size() - 1; i >= 0; --i) {
       if(vals[i] <= s) {
           s -= vals[i];
           ans.push_back(vals[i]);
       }
   }

   cout << ans.size() + 1 << endl;
   for(int i = 0; i < ans.size(); ++i) {
       cout << ans[i] << ' ';
   }
   cout << 0 << endl;
   return 0;
}