//플로이드 2

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>

using namespace std;

int path[101][101];
int cost[101][101];
int INF = INT_MAX;
int p[101][101];
vector<int> v;

void findpath(int, int);

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
        p[a][b] = a;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(path[i][k]!=INF && path[k][j]!=INF && path[i][k] + path[k][j] < path[i][j]){
                    path[i][j] = path[i][k] + path[k][j];
                    p[i][j] = k;
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

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) {
                cout << 0 << '\n';
                continue;
            }
            findpath(i,j);
            cout << v.size() << ' ';
            for(int k=0; k<v.size();k++){
                cout << v[k] << ' ';
            }
            cout << '\n';
            v.clear();
        }
    }
}

void findpath(int start, int end) {
    if(p[start][end] == start) {
        v.push_back(start);
        v.push_back(end);
        return;
    }
    findpath(start, p[start][end]);
    v.pop_back();
    findpath(p[start][end], end);
}