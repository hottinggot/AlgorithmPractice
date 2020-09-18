//쉬운 계단 수

#include<iostream>

using namespace std;

long long mod = 1000000000LL;

long long D[101][10];
long long d[101];

long long ans(int n, int l){

    if(D[n][l]>0) return D[n][l];

    if(n<=0) return 0;

    if(l<0 || l>=10) return 0;

    if(n==1) D[n][l]=1;
    else{
        if(l==9) D[n][l] = ans(n-1,l-1)%mod;
        else if(l==0) D[n][l] = ans(n-1,l+1)%mod;
        else  D[n][l] = (ans(n-1,l+1)%mod+ ans(n-1,l-1)%mod)%mod;
        
    } 

     
    d[n] += D[n][l];
    d[n] %= mod;


    return D[n][l]%mod;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1;i<=9;i++){
        ans(n,i);
    }
    

    cout <<  d[n]%mod << '\n';


}