/*
  We can observe that the first and the last element of the segment must be distinct,
So we maintain two forward iterator and a map containing the numbers and count of the segment, once we found a acceptable segment, update the result.
  The method to iterator the two iterator (i and j) are obviously in the code.
  So finally, the time complexity of this problem is O(n).
*/


#include <iostream>
#include <map>
using namespace std;

int main() {
   int n, k;
   int a[100000];
   cin >> n >> k;
   map<int, int> mp;
   int beg = -1, end = -1;
   for(int i = 0, j = 0; i < n; ++i) {
       cin >> a[i];
       if(++mp[a[i]] == 1) {
           while(mp.size() > k) {
               if(!--mp[a[j]]) {
                   mp.erase(mp.find(a[j]));
               }
               ++j;
           }
           if(mp.size() == k) {
               while(mp[a[j]] > 1) {
                   mp[a[j++]]--;
               }
               if(beg == -1 || end-beg > i-j) {
                   beg = j+1;
                   end = i+1;
               } 
           }
       }
   }
   cout << beg << ' ' << end << endl;
   return 0;
}