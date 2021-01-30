//특정한 최단 경로

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

ll cost[801][801];
ll INF = 200000001;

int main() {
    int n, e;
    cin >> n >> e;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(i==j) continue;
            cost[i][j] = INF;
        }
    }

    for(int i=0; i<e; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        cost[a][b] = min(cost[a][b], c);
        cost[b][a] = cost[a][b];
        
    }
    int v1, v2;
    cin >> v1 >> v2;

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i==j) continue;
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }

    ll temp1 = cost[1][v1] + cost[v1][v2] + cost[v2][n];
    ll temp2 = cost[1][v2] + cost[v2][v1] + cost[v1][n];

    if(min(temp1, temp2) >= INF) cout << -1 << '\n';
    else 
    cout << min(temp1, temp2) << '\n';

}