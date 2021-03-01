//할 일 정하기 1

#include<iostream>

using namespace std;

int n;
int D[20][20];
int memo[(1<<20)];
int INF = 10000*21;

int dfs(int k, int visit) {
    if(visit==(1<<n)-1) {
        return 0;
    }

    if(memo[visit]>0) return memo[visit];

    int temp = INF;

    for(int i=0; i<n; i++) {
        if(visit & (1<<i)) continue;
        temp = min(temp , D[k][i] + dfs(k+1, visit|(1<<i)));
    }
    memo[visit] = temp;
    return temp;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> D[i][j];
        }
    }

    cout << dfs(0,0) << '\n';
}