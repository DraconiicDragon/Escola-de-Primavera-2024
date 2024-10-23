#include <iostream>
#include <vector>

using namespace std;

struct Bit {
    int n;
    vector<long long> bit;

    Bit(int _n=0) : n(_n), bit(n + 1) {}

    // Soma x na posição i (i sendo uma  posição 0 indexada)
    void update(int i, long long x) {
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }

    // Soma de [0, i]
    int pref(int i) {
        long long ret = 0;
        for(i++; i; i -= i & -i) ret += bit[i];
        return ret;
    }
};

int main() {
    int n;
    cin >> n;
    Bit frequencia(n), parcrescente(n);
    long long resposta = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a = n - a;
        resposta += parcrescente.pref(a - 1);
        parcrescente.update(a, frequencia.pref(a - 1));
        frequencia.update(a, 1);
    }
    cout << resposta << endl;
    return 0;
}