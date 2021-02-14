//미확인 도착지

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int INF = 2e9;

vector<pair<int, int>> map[2002];
int dist[2002];
int n, m, t;
int s, g, h;
vector<int> goal;

void dijkstra(int start) {
    
    priority_queue<pair<int,int>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int newStart = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        if(dist[newStart] < cost) continue;

        for(int i=0; i<map[newStart].size(); i++) {
            if(dist[map[newStart][i].first] > dist[newStart] + map[newStart][i].second) {
                dist[map[newStart][i].first] = dist[newStart] + map[newStart][i].second;
                pq.push({-dist[map[newStart][i].first], map[newStart][i].first});
            }
        }
    }

}

int main() {
    int T;
    cin >> T;

    while(T--) {
        cin >> n >> m >> t;

        for(int i=0; i<2002; i++) {
            dist[i] = INF;
            map[i].clear();
        }
        goal.clear();
        
        cin >> s >> g >> h;

        for(int i=0; i<m; i++) {
            int a, b, d;
            cin >> a >> b >> d;

            if((a==g && b==h) || (a==h && b==g)){
                map[a].push_back({b, 2*d-1});
                map[b].push_back({a, 2*d-1});
            } else {
                map[a].push_back({b, 2*d});
                map[b].push_back({a, 2*d});
            }

        }
   
        for(int i=0; i<t; i++) {
            int x;
            cin >> x;

            goal.push_back(x);
        }

        dijkstra(s);

        sort(goal.begin(), goal.end());
        
        for(int i=0; i<goal.size(); i++) {
            if(dist[goal[i]]%2==1) cout << goal[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}