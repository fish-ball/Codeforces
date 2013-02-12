/*
  Using a data-structure to compress the information.
  For each string inputted, and for all positions, calculate the shortest distance between the previous 1 and the next 1. The minimum of the two values is the cost of this single string at this position.
  So summing the costs at each position for all the inputs, and finally choose the minimum of the summing at all positions to be the result. 
*/


#include <cstring>
#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int cnext(int* nxt, const string& s, int k) {
   if(nxt[k] != -1) return nxt[k];
   else if(s[k] == '1') return nxt[k] = 0;
   else return nxt[k] = cnext(nxt, s, (k + 1) % s.size()) + 1;
}

int cprev(int* pre, const string& s, int k){
   if(pre[k] != -1) return pre[k];
   else if(s[k] == '1') return pre[k] = 0;
   else return pre[k] = cprev(pre, s, (k + s.size() - 1) % s.size()) + 1;
}

int main() {
   string s;
   int pre[10000] = {}, nxt[10000] = {}, cnt[10000] = {};
   int n, m, result = 0x7FFFFFFF;
   for(cin >> n >> m; n--; ) {
       cin >> s;
       if(result == -1 || s.find('1') == string::npos) {
           result = -1;
           continue;
       }
       memset(pre, -1, sizeof(pre));
       memset(nxt, -1, sizeof(nxt));
       for(int i = 0; i < m; ++i) {
           if(nxt[i] == -1) cnext(nxt, s, i);
           if(pre[i] == -1) cprev(pre, s, i);
           cnt[i] += min(nxt[i], pre[i]);
       }
   }
   if(result != -1) {
       for(int i = 0; i < m; ++i) {
           result = min(result, cnt[i]); 
       } 
   } 
   cout << result << endl; 
   return 0;
}