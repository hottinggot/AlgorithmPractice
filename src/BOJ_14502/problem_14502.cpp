//연구소

#include<iostream>
#include<vector>

using namespace std;
int n,m;
int map[9][9];
vector<pair<int, int>> v[9][9];
bool check[9][9];

int minVal = -1;
int number;

void dfs(int x, int y) {
    
    for(int i=0; i<v[x][y].size(); i++) {
        
        if(!check[v[x][y][i].first][v[x][y][i].second] && map[v[x][y][i].first][v[x][y][i].second] == 0) {
            check[v[x][y][i].first][v[x][y][i].second] = 1;
            number++;
            dfs(v[x][y][i].first, v[x][y][i].second);
        }
    }
}

int countMin() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            check[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==2) {
                dfs(i, j);
             }
        }
    }
    int temp = number;
    number = 0;
    return temp;
}
 
void bt(int cnt) {
    if(cnt==3) {
        
        if(minVal == -1 || minVal>countMin())
            minVal = countMin();
        return;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==0) {
                map[i][j] = 1;
                cnt++;
                bt(cnt);
                cnt--;
                map[i][j] = 0;
            }
        }
    }
}

int main() {

    int count = 0;
    
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];

            if(map[i][j]!=0) count++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]!=1) {
                if(i+1<n && map[i+1][j]==0) {
                    v[i][j].push_back({i+1, j});
                }
                if(i-1>=0 && map[i-1][j]==0) {
                    v[i][j].push_back({i-1, j});
                }
                if(j+1<m && map[i][j+1]==0) {
                    v[i][j].push_back({i, j+1});
                }
                if(j-1>=0 && map[i][j-1]==0) {
                    v[i][j].push_back({i, j-1});
                }
            }
        }
    }

    bt(0);

    cout << n*m - minVal - count - 3 << '\n';
}