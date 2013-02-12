/*
  Counting the triangles, figure that the Alice's edge set as A, while Bobs's as B.
  And the full graph has C(n, 3) triangles, while the A set destroy part of them.
  Now count them by the inclusion-exclusion principal:
  Let the full count of the full graph be T0 = C(n, 3);
  That each edge in A destroys n-2 triangles(each vertex except the two of the edge forms a triangle), so let T1 = m * (n - 2);
  Then, if two sides of a triangle are both inside A, the triangle is destroyed once more, so we count all edges which has a common vertex, and each pair forms a triangle, we should add them back to the result. Suppose there are k vertexes mentioned in a, grouping them by distinct vertexes and each group has G(i) edges, i.e. was mentioned G(i) times. So each group has C(G(i), 2) pairs of edges in a same triangles, finally, we make T2 = sum(C(G(i), 2)) of all groups.
  Then if all the three sides of a triangle is in A, it has been add back once more, so we must subtract them back, make the count as T3.
  So finally, we know the number of all triangles in B is T0 - T1 + T2 - T3, where T3 is still unknown.
  Fortunately, the result we want to get is count(A) + count(B), and count(A) is right equals T3, so the final result is T0 - T1 + T2. Thats all.
*/


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long i64;

int main() {
   i64 n, m, x, y;
   scanf("%I64d%I64d", &n, &m);
   vector<int> v(n, 0);
   i64 a = 0, b = 0, c = 0;
   a = n * (n - 1) * (n - 2) / 6;
    b = m * (n - 2);
   for(int i = 0; i < m; ++i) {
       scanf("%I64d%I64d", &x, &y);
       ++v[x-1];
       ++v[y-1];
   }
   for(int i = v.size() - 1; i >= 0; --i) {
       c += v[i] * (v[i] - 1) / 2;
   }
   printf("%I64d\n", a - b + c);
   return 0;
}