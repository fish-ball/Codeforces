/*
Simple implementation.
Be careful to read the problems, the sequence matters.
*/


#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    string names[1000];
    int scores[1000];
    int n(0);
    cin >> n;
    map<string, int> dic;
    for(int i = 0; i < n; ++i) {
        cin >> names[i] >> scores[i];
        dic[names[i]] += scores[i];
    }
    int m(0);
    set<string> winners;
    for(map<string, int>::iterator iter = dic.begin();
            iter != dic.end(); ++iter) {
        if(iter->second > m) {
            winners.clear();
            m = iter->second;
        }
        if(iter->second == m) {
            winners.insert(iter->first);
        }
    }
    dic.clear();
    for(int i = 0; i < n; ++i) {
        if(winners.find(names[i]) != winners.end()) {
            dic[names[i]] += scores[i];
            if(dic[names[i]] >= m) {
                cout << names[i] << endl;
                break;
            }
        }
    }
    return 0;
}