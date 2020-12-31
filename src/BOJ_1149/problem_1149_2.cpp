//RGB거리

#include<iostream>

using namespace std;

int cost[1001][3];
int D[1001][3];

int dp(int n, int c){

    if(n == 0) return 0;

    if(D[n][c]>0) return D[n][c];

    if(c==0) D[n][c] = min(dp(n-1, 1), dp(n-1,2)) + cost[n][c];
    else if(c==1) D[n][c] = min(dp(n-1, 0), dp(n-1,2)) + cost[n][c];
    else D[n][c] = min(dp(n-1, 0), dp(n-1,1)) + cost[n][c];


    return D[n][c];

}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    cout << min(min(dp(n,0), dp(n,1)), dp(n,2)) << '\n';
    
}