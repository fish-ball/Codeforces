// Just output but skipping the first 0 from left.
// Be care of the case which contains no 0's. 

#include <cstdio>
#include <cstring>

char s[100001];

int main() {
    scanf("%s", s);
    bool found = false;
    for(char* c = s; *c; ++c) {
        if(!found && (*c == '0' || !*(c+1))) found = true;
        else putchar(*c);
    }
    puts("");
    return 0;
}