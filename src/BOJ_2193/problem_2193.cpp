//이친수

#include<iostream>

using namespace std;

long long D[91];

long long ans(int n){
    if(D[n]>0) return D[n];
    if(n<=0) return 0;
    if(n==1 || n==2) return 1;

    if(n>2)
        D[n] = ans(n-1) + ans(n-2);

    return D[n];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << ans(n) <<'\n';

}