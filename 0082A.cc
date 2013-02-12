/*
  Simply enumerates the round k(0-based), and the queue length is (5<<k), until the accumeration s reaches the given n.
  Then the continuous person length of this step is (1<<k), so the result is (n-1-s)/(1<<k).
  Totally time complexity is O(log2(n)).
*/


#include <iostream>
using namespace std;

int main() {
   char* str[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
   int n;
   cin >> n;
   int k = 0, s = 0;
   while(s + (5<<k) < n) s += (5<<k++);
   cout << str[(n - 1 - s) / (1<<k)] << endl; 
   return 0;
}