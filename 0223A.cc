/*
  All we need to do here is just parse the bracket strings, and storing the maximum matched sub-string.
  We can store the unclosed brackets in a stack, containing the beginning tag on each level. Also, we must store the prefix and score of each level, e.g. [([])()] for input, when parsing to the position: [([]), the level is then reduce to 1, the bracket stack on this level is [, and the prefix on this level is ([]), the score on this level is 1. Then, once we found a greater score, we update the result.
  On thing should be careful, that we shouldn't store the prefix explicit, because for a trivial implementation, operating the prefix string may costs O(n^2) time, which would absolutely ran exceeds the time limit.
  So we should store the prefix just as the first index, that's enough. also, when we store the output string and current string, use begin-end index would take effect.
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
   string input;
   int maxv = 0, score = 0;
   int outbeg = 0, outend = -1;
   int curbeg = 0, curend = 0;
   vector<char> stk(0);
   vector<int> prefixes(0);
   vector<int> scores(0);
   cin >> input;
   for(int i = 0; i < input.size(); ++i) {
       if(input[i] == '[' || input[i] == '(') {
           stk.push_back(input[i]);
           prefixes.push_back(curbeg);
           scores.push_back(score);
           score = 0;
           curbeg = i + 1;
       }
       if(input[i] == ')') {
           if(stk.size() && stk.back() == '(') {
               stk.pop_back();
               curbeg = prefixes.back();
               curend = i;
               prefixes.pop_back();
               score += scores.back();
               scores.pop_back();
               if(score > maxv) {
                   outbeg = curbeg;
                   outend = curend;
                   maxv = score;
               }
           }
           else {
               stk.clear();
               prefixes.clear();
               scores.clear();
               score = 0;
               curbeg = i + 1;
           }
       }
       if(input[i] == ']') {
           if(stk.size() && stk.back() == '[') {
               stk.pop_back();
               curbeg = prefixes.back();
               curend = i;
               prefixes.pop_back();
               score += scores.back() + 1;
               scores.pop_back();
               if(score > maxv) {
                   outbeg = curbeg;
                   outend = curend;
                   maxv = score;
               }
           }
           else {
               stk.clear();
               prefixes.clear();
               scores.clear();
               score = 0;
               curbeg = i + 1;
           }
       }
   }
   cout << maxv << endl;
   cout << input.substr(outbeg, outend-outbeg+1) << endl;
   return 0;
}