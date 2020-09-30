//단지번호붙이기

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> list[26][26];
bool check[26][26];
int cnt=0;

void dfs(int row, int col){

    cnt++;

    for(int i=0; i<list[row][col].size(); i++){
        pair<int, int> x = list[row][col][i];
        if(!check[x.first][x.second]){
            check[x.first][x.second]=true;
            dfs(x.first, x.second);
        }
            
    }

}

int main(){
    int n;
    cin >> n;

    int map[n+1][n+1];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%1d", &map[i][j]);
            
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j]){
                //left
                if(j-1>0 && map[i][j-1]==1) list[i][j].push_back({i, j-1});
                //right
                if(j+1<=n && map[i][j+1]==1) list[i][j].push_back({i, j+1});
                //up
                if(i-1>0 && map[i-1][j]==1) list[i][j].push_back({i-1, j});
                //down
                if(i+1<=n && map[i+1][j]==1) list[i][j].push_back({i+1, j});
            }
        }
    }

    vector<int> num;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!check[i][j] && map[i][j]){
                check[i][j] = true;
                dfs(i,j);
            }
            if(cnt>0) {
                num.push_back(cnt);
                cnt=0;
            }
        }
    }

    sort(num.begin(), num.end());

    cout << num.size() << '\n';
    for(int i=0; i<num.size(); i++){
        cout << num[i] << '\n';
    }

   
    

}