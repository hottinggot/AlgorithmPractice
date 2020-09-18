//2×n 타일링 2

#include<iostream>

using namespace std;

int memo[1001];

int tile2(int n){
    if(memo[n]>0) return memo[n];

    if(n<0) return 0;
    else if(n==0 || n==1) return 1;

    memo[n] = (2*tile2(n-2)%10007)%10007 + tile2(n-1)%10007;
    return memo[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << tile2(n)%10007 << '\n';


}