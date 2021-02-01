//외판원 순회

#include<iostream>

using namespace std;

int INF = 1000000000;
int n;
int W[16][16];
int D[16][1<<16];

int dfs(int current, int visit) {
    if(visit == (1<<n)-1) {
        if(W[current][0]==0) return INF;
        else return W[current][0];
    }

    if(D[current][visit]>0) return D[current][visit];
    D[current][visit] = INF;

    for(int i=0; i<n; i++) {
        if(W[current][i]==0 || visit & (1<<i)) continue;
        D[current][visit] = min(D[current][visit], W[current][i] + dfs(i, visit|(1<<i)));
    }
    return D[current][visit];
}

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> W[i][j];
        }
    }

    cout << dfs(0,1) << '\n';
}