//최단경로

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> list[20001];
int dist[20001];

#define INF 1000000

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({dist[start] = 0, start});
    
    while(!pq.empty()){
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        if(x>dist[y]) continue;

        for(int i=0; i<list[y].size(); i++) {
            int newDist = list[y][i].first + dist[y];
            int newY = list[y][i].second;
            if(dist[newY] > newDist){
                dist[newY] = newDist;
                pq.push({-newDist, newY});
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, k;
    cin >> n >> e >> k;

    for(int i=0; i<e; i++) {
        int u,v,w;
        cin >> u >> v >> w;

        list[u].push_back({w,v});
    }

    for(int i=0 ; i<=n;i++) {
        dist[i] = INF;
    }

    dijkstra(k);

    for(int i=1; i<=n;i++) {
        if(dist[i] == INF){
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        } 
    }
}