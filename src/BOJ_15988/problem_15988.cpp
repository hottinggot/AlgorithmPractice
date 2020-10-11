//1, 2, 3 더하기 3

#include<iostream>

using namespace std;

long long memo[1000001];
long long mod = 1000000009;

int main(){
    

    for(int i=1; i<=1000000; i++){
        if(i==1){
            memo[i]=1;
            continue;
        }
        if(i==2){
            memo[i]=2;
            continue;
        }
        if(i==3){
            memo[i]=4;
            continue;
        }
        if(i>3){
            memo[i] = (memo[i-1]%mod + memo[i-2]%mod + memo[i-3]%mod)%mod;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << memo[n]%mod << '\n';
    }
}