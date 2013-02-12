// Quite straight forward implementation.


#include <cctype>
#include <string>
#include <iostream>
using namespace std;

int main() {
   string s;
   cin >> s;
   bool yes = true;
   for(int i = 1; i < s.size(); ++i) {
       if(islower(s[i])) {
           yes = false;
           break;
       }
   }
   if(yes) {
       s[0] = isupper(s[0]) ? tolower(s[0]) : toupper(s[0]);
       for(int i = 1; i < s.size(); ++i) {
           s[i] = tolower(s[i]);
       }
   }
   cout << s << endl;
   return 0;
}