//섬의 개수

#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> list[51][51];
bool check[51][51];

void dfs(int row, int col){
    for(int i=0; i<list[row][col].size(); i++){
        pair<int, int> x = list[row][col][i];
        if(!check[x.first][x.second]){
            check[x.first][x.second] = true;
            dfs(x.first, x.second);
        }
    }
}

int main(){
    int w,h;
    while(1){
        cin >> w >> h;

        if(w==0 && h==0) break;

        int map[h+1][w+1];

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++) {
                cin >> map[i][j];
            }
        }

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++) {
                if(map[i][j]==1){
                    //N
                    if(i-1>0 && map[i-1][j]==1) list[i][j].push_back({i-1, j});
                    //S
                    if(i+1<=h && map[i+1][j]==1) list[i][j].push_back({i+1, j});
                    //E
                    if(j+1<=w && map[i][j+1]==1) list[i][j].push_back({i, j+1});
                    //W
                    if(j-1>0 && map[i][j-1]==1) list[i][j].push_back({i, j-1});

                    //NE
                    if(i-1>0 && j+1<=w && map[i-1][j+1]==1) list[i][j].push_back({i-1, j+1});
                    //SE
                    if(i+1<=h && j+1<=w && map[i+1][j+1]==1) list[i][j].push_back({i+1, j+1});
                    //NW
                    if(j-1>0 && i-1>0 && map[i-1][j-1]==1) list[i][j].push_back({i-1, j-1});
                    //SW
                    if(i+1<=h && j-1>0 && map[i+1][j-1]==1) list[i][j].push_back({i+1, j-1});
                }
            }
        }

        int cnt = 0;

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(map[i][j]==1 && !check[i][j]){
                    check[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                list[i][j].clear();
                check[i][j]=0;
            }
        }

    }
}