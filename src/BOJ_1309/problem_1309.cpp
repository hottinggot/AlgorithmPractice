//동물원

#include<iostream>

using namespace std;

int D[100001][3];
int mod = 9901;


int main(){
    int n;
    cin >> n;

    D[1][0]=1;
    D[1][1]=1;
    D[1][2]=1;

    for(int i=2; i<=n; i++) {
        D[i][0] = (D[i-1][0]%mod + D[i-1][1]%mod + D[i-1][2]%mod)%mod;
        D[i][1] = (D[i-1][0]%mod + D[i-1][2]%mod)%mod;
        D[i][2] = (D[i-1][0]%mod + D[i-1][1]%mod)%mod;
    }

    cout << (D[n][0]%mod + D[n][1]%mod + D[n][2]%mod)%mod << '\n';





}