#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


class ParkingHeap {
public:
    vector<int> beg, end;
    map<int, int> lid, rid;
    int lot_count;
    
    inline int width(int l, int r) {
        if(l == 1) return r;
        else if(r == lot_count) return r - l + 1;
        else return r - l + 2 >> 1; 
    }
    
    inline bool comp(int i, int j) {
        return
            width(beg[i], end[i]) > width(beg[j], end[j]) ||
            width(beg[i], end[i]) == width(beg[j], end[j]) && beg[i] < beg[j];
    }
    
    void change(int i, int j) {
        swap(beg[i], beg[j]);
        swap(end[i], end[j]);
        swap(lid[beg[i]], lid[beg[j]]);
        swap(rid[end[i]], rid[end[j]]);
    }
    
    void move_up(int k) {
        while(k>1 && comp(k, k>>1)) {
            change(k, k>>1);
            k>>=1;
        }
    }
    
    void move_down(int k) {
        while((k<<1) < beg.size()) {
            int k1 = (k<<1), k2 = k1 + 1;
            int p = k2 == beg.size() || comp(k1, k2) ? k1 : k2;
            if(comp(p, k)) change(p, k);
            k = p;
        }
    }
    
    void push(int l, int r) {
        
        if(r < l) return;
        lid[l] = beg.size();
        rid[r] = end.size();
        beg.push_back(l);
        end.push_back(r);
        move_up(beg.size() - 1);
    }
    
    void rem(int k) {
        change(k, beg.size() - 1);
        lid.erase(beg.back());
        rid.erase(end.back());
        beg.pop_back();
        end.pop_back();
        move_down(k);
    }
    
    ParkingHeap(int n) : beg(1), end(1) {
        beg.push_back(1);
        end.push_back(n);
        lid[1] = 1;
        rid[n] = 1;
        lot_count = n;
    }
};


int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    ParkingHeap heap(n);
    map<int, int> pos;
    while(m--) {
        int t, p;
        cin >> t >> p;
        if(t == 1) {
            int l = heap.beg[1], r = heap.end[1], m = l+r>>1;
            if(l == 1) m = 1;
            else if(r == n) m = n;
            heap.rem(1);
            heap.push(l, m-1);
            heap.push(m+1, r);
            cout << (pos[p] = m) << endl;
        }
        else {
            int m = pos[p], l = m, r = m;
            pos.erase(p);
            if(heap.rid.find(m-1) != heap.rid.end()) {
                l = heap.beg[heap.rid[m-1]];
                heap.rem(heap.rid[m-1]);
            }
            if (heap.lid.find(m+1) != heap.lid.end()) {
                r = heap.end[heap.lid[m+1]];
                heap.rem(heap.lid[m+1]);
            }
            heap.push(l, r);
        }
    }
}