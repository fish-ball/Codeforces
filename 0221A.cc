/*
Simply observes that each 'sort' is the same as a left rotation of the array.
So dis-rotate it will get the solution.
*/


#include <iostream>
using namespace std;

int main() {
   int n(0);
   cin >> n;
   cout << n;
   for(int i = 1; i < n; ++i) {
       cout << " " << i;
   }
   cout << endl;
   return 0;
}