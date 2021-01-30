//운동

#include<iostream>

using namespace std;

int INF = 10001*400*400;

int main() {
    int v, e;
    cin >> v >> e;

    int cost[v+1][v+1];
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            cost[i][j] = INF;
        }
    }

    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cost[a][b] = c;
    }

    for(int k=1; k<=v; k++) {
        for(int i=1; i<=v; i++) {
            for(int j=1; j<=v; j++) {
                if(i==j) continue;
                if(cost[i][k]!= INF && cost[k][j]!= INF){
                    cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
                }
            }
        }
    }

    int minval = -1;
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            if(cost[i][j]!=INF && cost[j][i]!=INF) {
                if(minval == -1 || minval>cost[i][j]+cost[j][i]) minval = cost[i][j]+cost[j][i];
            }
        }
    }

    cout << minval << '\n';
}

