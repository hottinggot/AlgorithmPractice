//트리

#include<iostream>
#include<vector>

using namespace std;

vector<int> v[501];
bool check[501];

int dfs(int n, int before) {

    check[n] = 1;

    for(int i=0; i<v[n].size(); i++) {
        if(v[n][i]==before) continue;
        if(check[v[n][i]]) return 0;
        if(!dfs(v[n][i], n)) return 0;
    }

    return 1;

}

int main() {

    int index = 1;

    while(1) {
        int n,m;
        cin >> n >> m;

        if(n==0 && m==0) break;

        for(int i=0; i<m; i++) {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(check[i]==0) {
                if(dfs(i, 0)) cnt++;
            }
        }

        if(cnt==0) {
            cout << "Case " << index << ": No trees.\n";
        } else if(cnt == 1) {
            cout << "Case " << index << ": There is one tree.\n";
        } else {
            cout << "Case " << index << ": A forest of " << cnt << " trees.\n";
        }

        index++;

        for(int i=0; i<=n; i++) {
            check[i] = 0;
            v[i].clear();
        }
    }
}
 