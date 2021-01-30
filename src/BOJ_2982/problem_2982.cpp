//국왕의 방문

#include<iostream>
#include<vector>

using namespace std;

int list[1001][1001];
int INF = 987654321;

bool visited[1001];

int main() {
    int n,m;
    cin >> n >> m;

    int a, b, k, g;
    cin >> a >> b >> k >> g;

    int G[g+1];
    for(int i=1; i<=g; i++) {
        cin >> G[i];
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            list[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        list[u][v] = l;
        list[v][u] = l;
    }

    int Gtime[g+1];
    Gtime[G[1]] = 0;
    for(int i=2; i<=g; i++) {
        Gtime[G[i]] = Gtime[G[i-1]]+list[G[i-1]][G[i]];
    }

    int time[n+1];

    time[a] = k;
    
    for(int i=1; i<=n; i++) {
        int temp = time[a]+list[a][i];
        if(list[a][i]!=INF && (temp>Gtime[i] || Gtime[i]-temp>=list[a][i])) {
            time[i] = time[a]+list[a][i];
        }
        else time[i] = INF;
    }
    visited[a] = true;

    int cur = a;
    while(1) {
        int min = -1;
        for(int i=1; i<=n; i++) {
            if(min==-1 || time[i]<time[min]) min = i;
        }
        cur = min;
        visited[cur] = 1;
        if(cur==b) break;
        for(int i=1; i<=n; i++) {
            if(visited[i]!=1) {
                if(time[cur]>Gtime[cur] || Gtime[cur]-time[cur]>=list[cur][i]) {
                    int temp = time[cur]+list[cur][i];
                    if(temp < time[i]) {
                        time[i] = temp;
                    }
                } else {
                    int temp = time[cur]+list[cur][i]+ list[cur][i]-(Gtime[cur]-time[cur]);
                    if(temp < time[i]) {
                        time[i] = temp;
                    }
                }
            }
        }

    }

    cout << time[b] << '\n';
}