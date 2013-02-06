//   The key point is that if we mark the flow of each vertex,
// and search to decrease them from the source, and we will have
// at least one zero-in vertex at one time.

#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int> > > g(n);
    vector<int> f(n, 0), ans(m, -1);
    map<pair<int, int>, int> mp;
    
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[make_pair(a-1, b-1)] = i;
        f[a-1] += c;
        f[b-1] += c;
        g[a-1].push_back(make_pair(b-1, c));
        g[b-1].push_back(make_pair(a-1, c));
    }
    
    vector<int> q(1, 0);
    while(!q.empty()) {
        int v = q.back();
        q.pop_back();
        for(int i = 0; i < g[v].size(); ++i) {
            int w = g[v][i].first, c = g[v][i].second;
            pair<int, int> e = 
                (mp.find(make_pair(v, w)) != mp.end()) ? 
                make_pair(v, w) : make_pair(w, v);
            int k = mp[e];
            if(ans[k] == -1) {
                ans[k] = e.first == v ? 0 : 1;
                f[w] -= c + c;
                if(w < n-1 && f[w] == 0) {
                    q.push_back(w);
                }
            }
        }
    }
    
    for(int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
