//1, 2, 3 더하기

#include<iostream>

using namespace std;

int memo[12];

int ans(int n){

    if(memo[n]>1) return memo[n];
    if(n<=0) return 0;
    else if(n==1) {
        memo[n]=1;
        return 1;
    }
    else if(n==2) 
    {
        memo[n] = 2;
        return 2;
    }

    else if(n==3){
        memo[n] = 4;
        return 4;
    }
    else{
        memo[n] = ans(n-3) + ans(n-2) + ans(n-1);
        return memo[n];
    }
        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    while(x--){
        int n;
        cin >> n;
            cout << ans(n) << '\n';

    }

}