// Assume that the edges are x, y, z and the area is a, b, c.
// We can simply write: a=x*y, b=y*z, c=x*z, so x*x=a*c/b, y*y=a*b/c, z*z=b*c/a.
// All we do is just to calculate the square root efficiently.


#include <iostream>
using namespace std;

int mysqrt(int x) {
   int l = 0, r = x + 1;
   while(l < r - 1) {
       long long m = l + r >> 1;
       if(m * m <= x) l = m;
       else r = m;
   }
   return l;
}

int main() {
   int a, b, c;
   cin >> a >> b >> c;
   int x2 = b * c / a, y2 = a * c / b, z2 = a * b / c;
   cout << 4 * (mysqrt(b*c/a) + mysqrt(a*c/b) + mysqrt(a*b/c)) << endl;
   return 0;
}