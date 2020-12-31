//상범 빌딩

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, pair<int, int>>> list[31][31][31];
int check[31][31][31];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        int l,r,c;
        cin >> l >> r >> c;

        if(l==0 && r==0 && c==0) break;

        char arr[l+1][r+1][c+1];

        pair<int, pair<int, int>> startPoint;
        pair<int, pair<int, int>> endPoint;

        for (int i=1; i<=l; i++) {
            for(int j=1; j<=r; j++) {
                for(int k=1; k<=c; k++) {

                    char ch;
                    cin >> ch;

                    if(ch!='\n'){
                        arr[i][j][k] = ch;
                    }

                    if(ch=='S') startPoint = {i,{j,k}};
                    else if(ch=='E') endPoint = {i,{j,k}};
                }
            }
        }

        for (int i=1; i<=l; i++) {
            for(int j=1; j<=r; j++) {
                for(int k=1; k<=c; k++) {
                    if(arr[i][j][k]!='#'){
                        if(i-1>=1 && arr[i-1][j][k]!='#'){
                            list[i][j][k].push_back({i-1,{j,k}});
                            list[i-1][j][k].push_back({i,{j,k}});
                        }

                        if(j-1>=1 && arr[i][j-1][k]!='#'){
                            list[i][j][k].push_back({i,{j-1,k}});
                            list[i][j-1][k].push_back({i,{j,k}});
                        }

                        if(k-1>=1 && arr[i][j][k-1]!='#'){
                            list[i][j][k].push_back({i,{j,k-1}});
                            list[i][j][k-1].push_back({i,{j,k}});
                        }
                        
                    }
                }
            }
        }

        queue<pair<int, pair<int, int>>> q;
        q.push(startPoint);
        check[startPoint.first][startPoint.second.first][startPoint.second.second] = 1;

        int a1=0,a2=0,a3=0;
        bool isSucceed = false;

        while(!q.empty()) {
            pair<int, pair<int, int>> f = q.front();
            q.pop();

            for(int i=0; i<list[f.first][f.second.first][f.second.second].size(); i++) {
                int x = list[f.first][f.second.first][f.second.second][i].first;
                int y = list[f.first][f.second.first][f.second.second][i].second.first;
                int z = list[f.first][f.second.first][f.second.second][i].second.second;

                if(check[x][y][z]==0){
                    q.push({x,{y,z}});
                    check[x][y][z] = check[f.first][f.second.first][f.second.second] + 1;
                }

                if(x==endPoint.first && y == endPoint.second.first && z == endPoint.second.second){
                    a1=x; a2=y; a3=z;
                    isSucceed = true;
                    break;
                }
            }
        }

        if(isSucceed)
            cout << "Escaped in " << check[a1][a2][a3]-1 << " minute(s).\n";
        else
            cout << "Trapped!\n";

        for (int i=1; i<=l; i++) {
            for(int j=1; j<=r; j++) {
                for(int k=1; k<=c; k++) {
                    list[i][j][k].clear();
                    check[i][j][k] = 0;

                }
            }
        }


    }
}