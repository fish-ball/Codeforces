#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 0. Depth First Search to get: 
//      level: the relative level of each node.
//      return: the absolute level of the subtree of v.
//          and finally the absolute level of the first node. 
int dfs(int v
        , int d
        , const vector<vector<int> >& g
        , vector<int>& level) {
    level[v] = d;
    int result = 0;
    for(int i = 0, w = 0; i < g[v].size(); ++i) {
        w = g[v][i];
        if(level[w>0?w:-w] == -0xFFFFFF) {
            if(w > 0) result += dfs(w, d+1, g, level);
            else result += 1 + dfs(-w, d-1, g, level);
        }
    }
    return result;
}


int main() {
    
    // 1. Generates the Graph.
    int n(0);
    cin >> n;
    // 1.1. Using the bidirection adj-list.
    vector<vector<int> > g(n + 1, vector<int>(0));
    // 1.2. Using 1-based index, 
    //      a negative destination means a reverse edge. 
    for(int i = 1; i < n; ++i) {
        int x(0), y(0);
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(-x);
    }
    
    // 2. Calculate the level of each node.
    //    Define the level as the changes need on v;
    //    We can observe that if exists <v, w>, 
    //    then level[v] = level[w] - 1; 
    // 2.1. So, let level be the relative level of node 1.
    //    i.e. level[1] = 0
    //    here, -0xFFFFFF means not visited.    
    vector<int> level(n + 1, -0xFFFFFF);
    // 2.2. DFS to calculate the relative level into level[].
    //    and also return the absolute level of node 1.
    //    So finally, base_level + level[v] indicates
    //    the absolute level of node v. 
    int base_level = dfs(1, 0, g, level);
    
    // 3. Get the answer.
    // 3.1. Traverse level[] to get the lowest relative level. 
    int min_level = 0xFFFFFF;
    for(int i = 1; i <= n; ++i) {
        min_level = min(min_level, level[i]);
    }
    // 3.2. All we need is the lowest absolute level, output it. 
    cout << base_level + min_level << endl;
    // 3.3. And also output all the nodes which level is minimum. 
    for(int i = 1, k = 0; i <= n; ++i) {
        if(level[i] == min_level) {
            cout << (k++ ? " " : "") << i;
        }
    }
    cout << endl;
    
    return 0;
}