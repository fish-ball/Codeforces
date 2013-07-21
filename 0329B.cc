#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

int G[1000][1000];
char MP[1000][1000];

int main() {
    
    int R, C, x, y;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    scanf("%d%d", &R, &C);
    
    int sx, sy, ex, ey;
    for(int i = 0; i < R; ++i) {
        scanf("%s", MP[i]);
        for(int j = 0; j < C; ++j) {
            if(MP[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            if(MP[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    
    deque<pair<int, int> > Q;
    memset(G, -1, sizeof(G));
    G[ex][ey] = 0;
    Q.push_back(make_pair(ex, ey));
    
    while(!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        int v = G[x][y];
        Q.pop_front();
        for(int d = 0; d < 4; ++d) {
            x += dx[d];
            y += dy[d];
            if(x>=0 && x<R && y>=0 && y<C && G[x][y]==-1 && MP[x][y] != 'T') {
                G[x][y] = v+1;
                Q.push_back(make_pair(x, y));
            }
            x -= dx[d];
            y -= dy[d];
        }
    }
    
    int t = G[sx][sy];
    int ans = 0;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(MP[i][j]>='1' && MP[i][j]<='9' && G[i][j]>-1 && G[i][j]<=t) {
                ans += int(MP[i][j]-'0');
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
