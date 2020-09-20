//제곱수의 합

#include<iostream>

using namespace std;

int D[100001];

int ans(int n){
    if(D[n]>0) return D[n];

    if(n==0) return 0;
    if(n==1)  return 1;

    for(int i=1; i*i<=n; i++){
        int temp = 1+ans(n-i*i);
        if(D[n]==0) D[n]=temp;
        if(temp<D[n]) D[n] = temp;
    }

    return D[n];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << ans(n) << '\n';

}