/*
  The essential point of a winning strategy is: First put the circle right on the center, then do the mirror operation after each move of the second player.
  So if the first move is available, the FIRST player wins, otherwise, the SECOND player wins.
*/


#include <iostream>
using namespace std;

int main() {
   int w, h, r;
   cin >> w >> h >> r;
   cout << (w<r+r || h<r+r ? "Second" : "First") << endl;
   return 0;
}