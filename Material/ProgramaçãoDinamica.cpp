#include <iostream>
#include <vector>

using namespace std;


const int MAX = 112345;
long long tabela[MAX] = {0,1};
bool resolvido[MAX] = {true, true};

long long fib(int n) {
    if(resolvido[n]) return tabela[n];
    tabela[n] = fib(n-1) + fib(n-2);
    resolvido[n] = true;
    return tabela[n];
}

int coin_row(const vector<int>& moedas, vector<int>& memoria, int n) {
    if(n < 0) return 0;
    if(memoria[n] != -1) return memoria[n];
    memoria[n] = max(moedas[n] + coin_row(moedas, memoria, n-2), coin_row(moedas, memoria, n-1));
    return memoria[n];
}

bool troco(const vector<int>& moedas, int k) {
    vector<bool> possivel(k+1, false);
    possivel[0] = true;
    for(int i = 0; i < k; i++) {

        if(!possivel[i]) continue;

        for(int c : moedas) {
            if(i+c <= k) possivel[i+c] = true;
        }
    }
    return possivel[k];
}

int coin_collecting(const vector<vector<int>>& mapa, vector<vector<int>>& memoria, int x, int y) {
    if(x < 0 || y < 0) return 0;
    if(memoria[x][y] != -1) return memoria[x][y];
    memoria[x][y] = max(coin_collecting(mapa, memoria, x-1, y), coin_collecting(mapa, memoria, x, y-1)) + mapa[x][y];
    return memoria[x][y];
}

int main() {

    /*
    vector<int> moedas = {5, 1, 2, 10, 6, 2};
    vector<int> memoria(moedas.size()+1, -1);
    cout << coin_row(moedas, memoria, moedas.size()-1);
    */

    /*
    vector<int> moedas = {3, 7, 15};
    cout << troco(moedas, 15);
    return 0;
    */

    int n = 5, m = 6;
    vector<vector<int>> mapa(n, vector<int>(m, 0));
    vector<vector<int>> memoria(n, vector<int>(m, -1));

    mapa[0][4] = 1;
    mapa[1][1] = 1;
    mapa[1][3] = 1;
    mapa[2][3] = 1;
    mapa[2][5] = 1;
    mapa[3][2] = 1;
    mapa[3][5] = 1;
    mapa[4][0] = 1;
    mapa[4][4] = 1;
    cout << coin_collecting(mapa, memoria, n-1, m-1);
    return 0;
}