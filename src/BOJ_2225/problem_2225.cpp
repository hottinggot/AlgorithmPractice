//합분해

#include<iostream>

using namespace std;

long long mod = 1000000000;

long long D[201][201];


long long ans(int n, int k){
    if(D[n][k]>0) return D[n][k];

    if(k==1) return 1;

    for(int i=0; i<=n; i++){
        D[n][k] += ans(n-i,k-1);
        D[n][k] %= mod;
    }
    return D[n][k];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    cout << ans(n,k)%mod << '\n';


}