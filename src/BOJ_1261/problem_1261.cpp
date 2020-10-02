//알고스팟

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int check[101][101];
vector<pair<int, int>> list[101][101];

int main(){
    int n,m;
    cin >> m >> n;
    
    int miro[n+1][m+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d",&miro[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i-1>0) list[i][j].push_back({i-1,j});
            if(i+1<=n) list[i][j].push_back({i+1,j});
            if(j-1>0) list[i][j].push_back({i,j-1});
            if(j+1<=m) list[i][j].push_back({i,j+1});
        }
    }

    queue<pair<int,int>> q0;
    queue<pair<int,int>> q1;

    q0.push({1,1});
    check[1][1]=1;

    while(!q0.empty()){
        while (!q0.empty()){
            pair<int, int> f0 = q0.front();
            q0.pop();

            for(int i=0; i<list[f0.first][f0.second].size(); i++){
                pair<int, int> x = list[f0.first][f0.second][i];

                if(check[x.first][x.second]==0 && miro[x.first][x.second]==0){
                    q0.push(x);
                    check[x.first][x.second] = check[f0.first][f0.second];
                }

                if(check[x.first][x.second]==0 && miro[x.first][x.second]==1){
                    q1.push(x);
                    check[x.first][x.second] = check[f0.first][f0.second] + 1;
                }
                
            }

            

            if(check[n][m]>0) break;

        }

        if(check[n][m]>0) break;

        while(!q1.empty()){
            q0.push(q1.front());
            q1.pop();
        }
        
    }

    cout << check[n][m]-1 << '\n';

}