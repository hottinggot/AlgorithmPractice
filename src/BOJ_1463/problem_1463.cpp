#include<iostream>

using namespace std;
int memo[1000001];

int go(int x){
    
    if(x==1) return 0;
    if(memo[x]>0) return memo[x];

    memo[x] = 1 + go(x-1);

    if(x%2==0){
        int temp = 1 + go(x/2);
        if(memo[x]>temp) memo[x] = temp;
    }

    if(x%3==0){
        int temp = 1+go(x/3);
        if(memo[x]>temp) memo[x] = temp;
    }

    return memo[x];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    cout << go(x) << '\n';

}