//다리 놓기

#include<iostream>

using namespace std;
typedef long long ll;

ll D[30][30];

int dp(int n, int m) {
    if(D[n][m]>0) return D[n][m];
    if(D[m-n][m]>0) {
        D[n][m] = D[m-n][m];
        return D[n][m];
    }

    if(n==m) return 1;
    if(n==1) return m;

    D[n][m] = dp(n-1,m-1) + dp(n, m-1);

    return D[n][m];
} 

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                D[i][j] = 0;
            }
        }

        cout << dp(n,m) << '\n';


    }
}