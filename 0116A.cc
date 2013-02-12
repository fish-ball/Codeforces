// Quite straight forward implementation...


#include <iostream>
using namespace std;

int main() {
   int n, a, b, current = 0, result = 0;
   for(cin >> n; n--;) {
       cin >> a >> b;
       current += b - a;
       if(current > result) result = current;
   }
   cout << result << endl;
   return 0;
}