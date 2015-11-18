#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n, i, x;
    scanf("%d", &n);
    map<int, int> mp; 
    for(i = 0; i < n; ++i) {
        scanf("%d", &x);
        mp[x] += 1;
        while(mp[x] == 2) {
            mp.erase(mp.find(x));
            mp[++x] += 1;
        }   
    }   
    printf("%d\n", (int)mp.size());
    return 0;
}
