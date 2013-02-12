#include <iostream>
#include <string>
using namespace std;


int main() {
    int k(0);
    string s("");
    cin >> k >> s;


    int count[26] = {};
    for(int i = 0; i < s.size(); ++i) {
        count[s[i]-'a']++;
    }
    
    string pattern("");
    for(int i = 0; i < 26; ++i) {
        if(count[i] == 0) continue;
        else if(count[i] % k == 0) {
            pattern += string(count[i] / k, 'a' + i);
        }
        else {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    for(int i = 0; i < k; ++i) {
        cout << pattern;
    }
    cout << endl;


    return 0;
}