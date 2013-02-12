// Quite straight forward execution...


#include <cstring>
#include <cstdio>
#include <cctype>

int main() {
   char c;
   while(c = getchar()) {
       if(c == 'a' || c == 'A' ||
               c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' ||
               c == 'o' || c == 'O' ||
               c == 'u' || c == 'U' ||
               c == 'y' || c == 'Y') {
           continue;
       }
       else if(isalpha(c)) {
           putchar('.');
           putchar(tolower(c));
       }
       else {
           putchar('\n');
           break;
       }
   } 
   return 0;
}