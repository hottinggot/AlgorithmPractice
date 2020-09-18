//1, 2, 3 더하기 5

#include<iostream>

using namespace std;

long long mod = 1000000009LL;

long long D[100001][4]={0};
long long d[100001]={0};

long long ans(int n, int i){

    if(n<0) return 0;

    if(D[n][i]>0) return D[n][i];

    if(n==0 && i>0) return 1;


    if(i==0) return (ans(n-1,1)%mod + ans(n-2,2)%mod+ ans(n-3,3)%mod)%mod ;
    else if(i==1) D[n][i] = (ans(n-2,2)%mod + ans(n-3,3)%mod)%mod ;
    else if(i==2) D[n][i] = (ans(n-1,1)%mod + ans(n-3,3)%mod)%mod ;
    else if(i==3) D[n][i] = (ans(n-1,1)%mod + ans(n-2,2)%mod)%mod ;


    return D[n][i];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;

    for(int i = 0; i<t; i++){
        cin >> n;
   
        //ans(n,0);
        cout << ans(n,0)%mod << '\n';
    }

    
}