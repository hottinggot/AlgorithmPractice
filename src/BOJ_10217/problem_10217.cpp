//KCM Travel

#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

int D[101][10001];
vector<pair<int,pair<int,int>>> list[101];
int INF = INT32_MAX;
int N;

int dp(int now, int cost) {

    if(cost<0) return INF;
    if(now==N) return 0;
    if(D[now][cost]>=0) return D[now][cost];
    
    int temp = INF;

    for(int i=0; i<list[now].size(); i++) {
        int next = list[now][i].first;
        int costAtNext = list[now][i].second.first;
        int timeAtNext = list[now][i].second.second;

        int t = dp(next, cost-costAtNext);
        if(t!=INF) temp = min(temp, t+timeAtNext);
    }
    
    D[now][cost] = temp;

    return D[now][cost];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int m, k;
        cin >> N >> m >> k;

        memset(D, -1, sizeof(D));

        for(int i=0; i<=N; i++) {
            list[i].clear();
        }
        
        for(int i=0; i<k; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            list[u].push_back({v, {c,d}});
        }

        int mini = dp(1, m);
        for(int i=m; i>=0; i--) {
            mini = min(mini, dp(1, i));
        }

        if(mini==INF) {
            cout << "Poor KCM\n";
        } else {
            cout << mini << '\n';
        }
    }
}