//   Maintain a matrix, which operates on swapping rows and cols, 
// and also query of a cell.
//   Simply swaps the index mapping instead of the data,
// leading to O(1) time-complexity for each operation.


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int data[1000][1000];
int row_rdx[1000], col_rdx[1000];

int main() {
   
   int n, m, q;
   cin >> n >> m >> q;
   for(int i = 0; i < n; ++i) {
       row_idx[i] = row_rdx[i] = i;
   }
   for(int i = 0; i < m; ++i) {
       col_idx[i] = col_rdx[i] = i;
   }
   
   for(int r = 0; r < n; ++r) {
       for(int c = 0; c < m; ++c) {
           cin >> data[r][c];
       }
   }
   
   while(q--) {
       string c;
       int x, y;
       cin >> c >> x >> y;
       if(c[0] == 'r') {
           swap(row_rdx[x-1], row_rdx[y-1]);
       }
       else if(c[0] == 'c') {
           swap(col_rdx[x-1], col_rdx[y-1]);
       }
       else if(c[0] == 'g') {
           cout << data[row_rdx[x-1]][col_rdx[y-1]] << endl;
       }
   }
   
   return 0;
}