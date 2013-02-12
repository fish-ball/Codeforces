/*
  Just use the dijkstra’s shortest path algorithm.
  Be careful that the occupy visitors only affects the leave time but not the enter time.
*/


#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
   int v, e;
   cin >> v >> e;
   vector<vector<pair<int, int> > > g(v);
   vector<set<int> > o(v);
   vector<int> t(v, -1);
   
   for(int i = 0; i < e; ++i) {
       int x, y, w;
       cin >> x >> y >> w;
       g[x-1].push_back(make_pair(y-1, w));
       g[y-1].push_back(make_pair(x-1, w));
   }
   
   for(int i = 0; i < v; ++i) {
       int n, k;
       for(cin >>n; n--;) {
           cin >> k;
           o[i].insert(k);
       }
   }
   
   priority_queue<pair<int, int> > q;
   
   q.push(make_pair(-0, 0));
   while(!q.empty()) {
       int tm = -q.top().first;
       int nd = q.top().second;
       q.pop();
       if(t[nd] != -1) continue;
       else t[nd] = tm;
       set<int>::iterator it = o[nd].find(tm);
       while(it != o[nd].end() && *it == tm) {
           ++tm;
           ++it;
       }
       for(int i = g[nd].size() - 1; i >= 0; --i) {
           int nx = g[nd][i].first;
           int cs = g[nd][i].second;
           if(t[nx] != -1) continue;
           q.push(make_pair(-cs-tm, nx));
       }
   }
   
   cout << t[v-1] << endl;
   return 0; 
}