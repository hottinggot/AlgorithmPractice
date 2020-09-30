//미로 탐색

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> list[101][101];
int check[101][101];

int main(){
    int n,m;
    cin >> n >> m;

    int miro[n+1][m+1];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &miro[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(miro[i][j]==1){
                //down
                if(i+1<=n && miro[i+1][j]==1) list[i][j].push_back({i+1, j});
                //up
                if(i-1>0&& miro[i-1][j]==1) list[i][j].push_back({i-1, j});
                //right
                if(j+1<=m && miro[i][j+1]==1) list[i][j].push_back({i, j+1});
                //left
                if(j-1>0 && miro[i][j-1]==1) list[i][j].push_back({i, j-1});
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({1,1});
    check[1][1] = 1;
    while(!q.empty()){
        pair<int, int> f = q.front();
        q.pop();

        for(int i=0; i<list[f.first][f.second].size(); i++){
            pair<int, int> x = list[f.first][f.second][i];
            if(x.first == n && x.second == m) {
                cout << check[f.first][f.second]+1 << '\n';
                return 0;
            }
            if(!check[x.first][x.second]){
                q.push(x);
                check[x.first][x.second] = check[f.first][f.second] +1;
            }
        }
    }
    

}