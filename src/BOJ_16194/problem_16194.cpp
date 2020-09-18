//카드 구매하기 2

#include<iostream>

using namespace std;

int memo[1001];
int cardsize;

int ans(int n, int * card){

    if(memo[n]>0) return memo[n];

    if(n<=0) return 0;

    for(int i=0; i<cardsize; i++){
        if(n-i-1<0) break;
        int temp = *(card+i)+ans(n-i-1,card);
        if(i==0) memo[n] = temp;
        if(temp < memo[n]) memo[n] = temp;
    }

    return memo[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cardsize = n;

    int card[n];
    for(int i=0;i<n;i++){
        cin>>card[i];
    }

    cout << ans(n, card) << '\n';


}