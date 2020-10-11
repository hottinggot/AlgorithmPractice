//RGB거리

#include<iostream>

using namespace std;

int memo[10001][3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int color[n+1][3];

    for(int i=1; i<=n; i++){
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    memo[1][0] = color[1][0];
    memo[1][1] = color[1][1];
    memo[1][2] = color[1][2];

    for(int i=2; i<=n; i++){
        memo[i][0] = min(memo[i-1][1], memo[i-1][2]) + color[i][0];
        memo[i][1] = min(memo[i-1][0], memo[i-1][2]) + color[i][1];
        memo[i][2] = min(memo[i-1][0], memo[i-1][1]) + color[i][2];
    }

    int min = memo[n][0];
    if(memo[n][1] < min) min = memo[n][1];
    if(memo[n][2] < min) min = memo[n][2];

    cout << min << '\n';

}