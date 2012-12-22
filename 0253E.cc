#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long i64;

struct Seg {
    Seg(i64 a, i64 b) : a(a), b(b) {}
    i64 a, b;
};

bool operator < (const Seg& x, const Seg& y) {
    return x.a < y.a || x.a == y.a && x.b < y.b;
}

i64 n, T;
i64 t0, s0, p0 = -1, i0;
vector<i64> px;
vector<pair<i64, Seg> > input;
map<Seg, i64> mp;
set<Seg> st;
map<i64, i64> idx;
i64 result[50000];

void update(i64 a, i64 b, i64 p) {
    set<Seg>::iterator it1 = st.upper_bound(Seg(a, 0x7FFFFFFF));
    set<Seg>::iterator it2 = it1--;
    i64 xbeg = a, xend = b, len;
    while(b - a >= 0) {
        xend = b;
        if(it1->b >= a) {
            xbeg = min(xbeg, it1->a);
            len = it1->b-a+1;
            a += len;
            b += len;
            continue;
        }
        if(it2 == st.end() || it2->a > b) {
            mp[Seg(a, b)] = p;
            st.insert(Seg(a, b));
            a += b-a+1;
            ++it1;
            if(it2 != st.end() && it2->a == b+1) {
                xend = it2->b;
                ++it2;
            }
        }
        else {
            len = it2->a-a;
            if(len == 0) {
                ++it1;
                ++it2;
                continue;
            }
            mp[Seg(a, a+len-1)] = p;
            st.insert(Seg(a, a+len-1));
            a += len;
            ++it1;
        }
    }
    st.erase(st.upper_bound(Seg(xbeg, xbeg-1)), it2);
    st.insert(Seg(xbeg, xend));
}

i64 check(i64 a, i64 b, i64 p) {
    map<Seg, i64>::iterator it1 = mp.upper_bound(Seg(a, 0x7FFFFFFF));
    map<Seg, i64>::iterator it2 = it1--;
    while(it2 != mp.end() && it2->second < p) ++it2;
    while(it1 != mp.begin() && it1->second < p) --it1;
    i64 len;
    while(b - a >= 0) {
        if(it1->first.b >= a) {
            len = it1->first.b-a+1;
            a += len;
            b += len;
            continue;
        }
        if(it2 == mp.end() || it2->first.a > b) return b;
        else {
            len = it2->first.a-a;
            if(len == 0) {
                ++it1;
                while(it1 != mp.end() && it1->second < p) ++it1;
                ++it2;
                while(it2 != mp.end() && it2->second < p) ++it2;
                continue;
            }
            a += len;
        }
    }
}

void build() {
    // sort by the priority descend.
    sort(input.rbegin(), input.rend());
    mp.clear();
    st.clear();
    mp[Seg(-1, -1)] = -1;
    st.insert(Seg(-1, -1));
    for(int i = 0; i < input.size(); ++i) {
        update(input[i].second.a, input[i].second.b, input[i].first);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    i64 t, s, p;
    // grab the inputs.
    for(int i = 0; i < n; ++i) {
        cin >> t >> s >> p;
        if(p == -1) {
            t0 = t;
            s0 = s;
            i0 = i;
        }
        else {
            input.push_back(make_pair(p, Seg(t, t+s-1)));
            idx[p] = i;
        }
    }
    cin >> T;
    // create the segment set.
    build();
    // build the probably priority values to search.
    px.push_back(input.front().first + 1);
    for(int i = 0; i < input.size()-1; ++i) {
        if(input[i+1].first+1 < input[i].first) {
            px.push_back(input[i+1].first+1);
        }
    }
    if(input.back().first > 1) { px.push_back(1); }
    // determine the priority and output.
    int l = 0, r = px.size(), m;
    while(l+1<r) {        
        m = l+r>>1;
        i64 chk = check(t0, t0+s0-1, px[m]);
        if(chk == T-1) {
            l = m;
            break;
        }
        else if(chk < T-1) {
            l = m;
        }
        else {
            r = m;
        }
    }
    p0 = px[l];
    cout << p0 << endl;
    idx[p0] = i0;
    // rebuild the segments.
    input.push_back(make_pair(p0, Seg(t0, t0+s0-1)));
    build();
    for(map<Seg, i64>::iterator it = mp.begin(); ++it != mp.end();) {
        result[idx[it->second]] = it->first.b+1;
    }
    for(int i = 0; i < n; ++i) {
        if(i) cout << ' ';
        cout << result[i];
    }
    cout << endl;
    return 0;
}
