//   The operation is equivalent that rotating the rear of the string,
// then popping from the front.
//   So, if all elements after k-position, the answer equals the index of 
// the last different element, otherwise the answer is -1.


#include <iostream>
using namespace std;

int main() {
   int n, k;
   cin >> n >> k;
   int j = 0, val = -1;
   for(int i = 0; i < n; ++i) {
       int tmp;
       cin >> tmp;
       if(tmp != val) {
           j = i;
           val = tmp;
       }
   }
   if(j < k) {
       cout << j << endl;
   }
   else {
       cout << -1 << endl;
   }
   return 0;
}