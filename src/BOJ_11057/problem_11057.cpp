//오르막 수

#include<iostream>

using namespace std;

int D[1001][10];
int mod = 10007;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<=9; i++) {
        D[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=9; j>=0; j--){
            for(int k=j; k>=0; k--){
                D[i][j] += D[i-1][k];
                D[i][j] %= mod;
            }
        }
    }

    int ans=0;
    for(int i=0; i<=9; i++){
        ans += D[n][i];
        ans %= mod;
    }

    cout << ans%mod << '\n';
}