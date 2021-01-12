//토마토

#include<iostream>
#include<queue>

using namespace std;

//vector<pair<int,pair<int,int>>> list[101][101][101];
int check[101][101][101];

int main() {
    int m,n,h;
    cin >> m >> n >> h;

    queue<pair<int,pair<int, int>>> q;

    for(int i=1; i<=h; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=m; k++) {
                cin >> check[i][j][k];
                if(check[i][j][k]==1) q.push({i, {j,k}});
            }
        }
    }

    while(!q.empty()){
        int z = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;

        q.pop();

        if(x+1<=m && check[z][y][x+1]==0){
            check[z][y][x+1] = check[z][y][x]+1;
            q.push({z,{y,x+1}});
        }
        if(x-1>0 && check[z][y][x-1]==0){
            check[z][y][x-1] = check[z][y][x]+1;
            q.push({z,{y,x-1}});
        }
        if(y+1<=n && check[z][y+1][x]==0){
            check[z][y+1][x] = check[z][y][x]+1;
            q.push({z,{y+1,x}});
        }
        if(y-1>0 && check[z][y-1][x]==0){
            check[z][y-1][x] = check[z][y][x]+1;
            q.push({z,{y-1,x}});
        }
        if(z+1<=h && check[z+1][y][x]==0) {
            check[z+1][y][x] = check[z][y][x]+1;
            q.push({z+1,{y,x}});
        }
        if(z-1>0 && check[z-1][y][x]==0){
            check[z-1][y][x] = check[z][y][x]+1;
            q.push({z-1,{y,x}});
        }
    }

    int max = 1;
    int cnt = 0;

    for(int i=1; i<=h; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=m; k++) {
                if(check[i][j][k]==0) {
                    cnt++;
                    break;
                }
                if(check[i][j][k]>max) max = check[i][j][k];
            }
        }
    }

    if(cnt>0) cout << -1 << '\n';
    else cout << max-1 << '\n';

}