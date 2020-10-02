//토마토

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> list[1001][1001];

bool check[1001][1001];

int main(){
    int m,n;    
    cin >> m >> n;

    int t[n+1][m+1];

    queue<pair<int, int>> q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> t[i][j];
            if(t[i][j]==1) {
                q.push({i,j});
                check[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(t[i][j]!=-1){
                if(j+1<=m && t[i][j+1]==0) list[i][j].push_back({i, j+1});
                if(j-1>0 && t[i][j-1]==0) list[i][j].push_back({i, j-1});
                if(i-1>0 && t[i-1][j]==0) list[i][j].push_back({i-1, j});
                if(i+1<=n && t[i+1][j]==0) list[i][j].push_back({i+1, j});
            }
        }
    }

    int d=0;
    int k=q.size();
    

    while(!q.empty()){
        
        pair<int, int> f = q.front();
        q.pop();
        k--;

        for(int i=0; i<list[f.first][f.second].size(); i++){
            pair<int, int> x = list[f.first][f.second][i];
            if(check[x.first][x.second]==0){
                q.push(x);
                check[x.first][x.second]=1;
            }
        }
        
        if(k==0) {
            d++;
            k = q.size();
            
        }
    }

    d--;

    int count=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(t[i][j]!=-1 && check[i][j]==0) d=-1;
            if(t[i][j]==0) count++;
        }
    }
    if(count==0) d=0; 

    cout << d <<'\n';
    
}