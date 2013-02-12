// Using a simple greedy strategy, just always fight with the currently weekest one.


#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int main() {
   int n, v;
   cin >> v >> n;
   vector<pair<int, int> > d;
   for(int i = 0; i < n; ++i) {
       int x, y;
       cin >> x >> y;
       d.push_back(make_pair(x, y));
   }
   sort(d.begin(), d.end());
   for(int i = 0; i < n; ++i) {
       if(v <= d[i].first) {
           v = -1;
           break;
       }
       v += d[i].second;
   }
   cout << (v > 0 ? "YES" : "NO") << endl;
   return 0; 
}