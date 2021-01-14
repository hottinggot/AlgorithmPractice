//플로이드

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>

using namespace std;

int path[101][101];
int INF = INT_MAX;

int main() {
    int n,m;
    cin >> n >> m;

    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            if(i==j) {
                path[i][j] = 0;
                continue;
            }
            path[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(path[a][b]!=INF && path[a][b]<c) continue;
        path[a][b] = c;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(path[i][k]!=INF && path[k][j]!=INF && path[i][k] + path[k][j] < path[i][j]){
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(path[i][j]==INF) path[i][j] = 0;
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }

}
