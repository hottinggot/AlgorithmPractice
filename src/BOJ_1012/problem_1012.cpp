//유기농 배추

#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> list[50][50];
bool check[50][50];
bool exist[50][50];

void dfs(pair<int,int> n) {
    check[n.first][n.second] = 1;
    for(int i=0; i<list[n.first][n.second].size(); i++) {
        pair<int,int> temp = list[n.first][n.second][i];
        if(exist[temp.first][temp.second] && !check[temp.first][temp.second]){
            check[temp.first][temp.second] = 1;
            dfs(temp);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m,n,k;
        cin >> m >> n >> k;

        for(int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;

            exist[y][x] = true;

            if(x+1<m) {
                list[y][x].push_back({y, x+1});
                list[y][x+1].push_back({y,x});
            }
            if(y+1<n) {
                list[y][x].push_back({y+1, x});
                list[y+1][x].push_back({y,x});
            }
        }

        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(exist[i][j] && !check[i][j]) {
                    dfs({i,j});
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                exist[i][j] = 0;
                check[i][j] = 0;
                list[i][j].clear();
            }
        }
        
    }
}