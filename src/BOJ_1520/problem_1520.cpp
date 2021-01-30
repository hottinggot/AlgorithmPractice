//내리막 길

#include<iostream>

using namespace std;

int m, n;
int map[501][501];
int D[501][501];

int dp(int y, int x, int h) {
    if(map[y][x]>=h) return 0;
    if(D[y][x]>=0) return D[y][x];
    if(y==m-1 && x==n-1) return 1;
    
    D[y][x] = 0;
    if(y+1<m) D[y][x] += dp(y+1,x,map[y][x]);
    if(y-1>=0) D[y][x] += dp(y-1,x,map[y][x]);
    if(x+1<n) D[y][x] += dp(y,x+1,map[y][x]);
    if(x-1>=0) D[y][x] += dp(y,x-1,map[y][x]);

    return D[y][x];
}

int main() {
    
    cin >> m >> n;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            D[i][j] = -1;
            cin >> map[i][j];
        }
    }

    cout << dp(0,0,10001) << '\n';
}