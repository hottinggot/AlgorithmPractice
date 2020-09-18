//2×n 타일링

#include<iostream>

using namespace std;

int memo[1001];

int tile(int n){
    if(memo[n]>0) return memo[n];

    if(n<0) return 0;
    if(n==0 || n==1) return 1;

    memo[n] = tile(n-2)%10007 + tile(n-1)%10007;
    return memo[n];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << tile(n)%10007 << '\n';

}