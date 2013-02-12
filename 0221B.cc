/*
To get the change count, we can simply sort the array then compares with the original one, the different element counts should be 0 or 2, meaning no swap or 1 swap.
*/


#include <iostream>
using namespace std;

int get_mask(int k) {
   int result = 0;
   while(k) {
       result |= (1<<k%10);
       k /= 10;
   }
   return result;
}

int main() {
   int x;
   cin >> x;
   int last = x;
   int mask_x = get_mask(x);
   int count = 0;
   for(int k = 1; k * k <= x; ++k) {
       if(x % k == 0) {
           if(mask_x & get_mask(k)) ++count;
           if((mask_x & get_mask(x / k)) && k * k != x) ++count;
       }
   }
   cout << count << endl;
   return 0;
}