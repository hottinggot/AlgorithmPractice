//타임머신

#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

ll INF = 987654321;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, ll>> v[n+1];
    ll dist[n+1];

    for(int i=2; i<=n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;

    for(int i=0; i<m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        bool t = 0;
        for(int i=0; i<v[a].size(); i++) {
            if(v[a][i].first == b) {
                v[a][i].second = min(v[a][i].second, c);
                t = 1;
                break;
            } 
        }
        if(t==0) v[a].push_back({b, c});
    }

    bool flag = 0;
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            if(dist[i]==INF) continue;
            for(int j=0; j<v[i].size(); j++) {
                if(dist[v[i][j].first]> dist[i] + v[i][j].second) {
                    dist[v[i][j].first] = dist[i] + v[i][j].second;
                    if(k==n){
                        flag = 1;
                    }
                }
            }
        }
    }

    if(flag==1) cout << -1;
    else {
        for(int i=2; i<=n; i++) {
            if(dist[i]>=INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }

    
   
    
}