/*
  The idea is find the circumcenter first, then find the angles and the minimum integer divisor of the angles.
  That is the edges of the polygon, then the area is easy to get.
*/


#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    
    // 1. Input the coordinates of the point.
    const double PI = acos(-1.0);
    double x1(0), y1(0), x2(0), y2(0), x3(0), y3(0);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    // 2. Calculate the center of the Polygon.
    //     i.e. the circumcenter of the triangle.
    // 2.1. Get two perpendicular bisector.
    double a1(x1-x2), b1(y1-y2), c1((x2*x2-x1*x1+y2*y2-y1*y1)/2);
    double a2(x1-x3), b2(y1-y3), c2((x3*x3-x1*x1+y3*y3-y1*y1)/2);
    // 2.2. Get the intersect to be the circumcenter.
    double x0((b1*c2-b2*c1)/(b2*a1-b1*a2));
    double y0((a1*c2-a2*c1)/(a2*b1-a1*b2));
    // 2.3. Get the radius.
    double r = hypot(x1-x0, y1-y0);
    
    // 3. Calculate the angles.
    double g1(fabs(acos(((x1-x0)*(x2-x0)+(y1-y0)*(y2-y0))/(r*r))));
    double g2(fabs(acos(((x1-x0)*(x3-x0)+(y1-y0)*(y3-y0))/(r*r))));
    double g3(PI + PI - g1 - g2);
    
    // 4. Caculates the partitions.
    int n = 2;
    while(++n <= 100) {
        double n1(0.5 * g1 * n / PI);
        double n2(0.5 * g2 * n / PI);
        double n3(0.5 * g3 * n / PI);
        if(fabs(n1 - round(n1)) < 1e-5
            && fabs(n2 - round(n2)) < 1e-5
            && fabs(n3 - round(n3)) < 1e-5) break;
    }
    
    printf("%0.8lf\n", 0.5 * n * sin((PI+PI)/n) * r * r);    
    return 0;
}