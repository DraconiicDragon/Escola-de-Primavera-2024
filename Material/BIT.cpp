#include <iostream>
#include <vector>

using namespace std;

struct Bit {
    int n;
    vector<int> bit;

    Bit(int _n=0) : n(_n), bit(n+1) {}

    // Soma x na posição i (i sendo uma  posição 0 indexada)
    void update(int i, int x) {
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }

    // Soma de [0, i]
    int pref(int i) {
        int ret = 0;
        for(i++; i; i -= i & -i) ret += bit[i];
        return ret;
    }
};
