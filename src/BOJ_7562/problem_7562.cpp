//나이트의 이동

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> list[301][301];
int check[301][301];

int main(){
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;

        pair<int, int> now;
        cin >> now.first >> now.second;

        now.first++;
        now.second++;

        pair<int, int> goal;
        cin >> goal.first >> goal.second;

        goal.first++;
        goal.second++;

        for(int i=1; i<=l; i++){
            for(int j=1; j<=l; j++){
                if(i-2>0 && j-1>0) list[i][j].push_back({i-2,j-1});
                if(i-1>0 && j-2>0) list[i][j].push_back({i-1,j-2});

                if(i+1<=l && j-2>0) list[i][j].push_back({i+1,j-2});
                if(i+2<=l && j-1>0) list[i][j].push_back({i+2,j-1});

                if(i-2>0 && j+1<=l) list[i][j].push_back({i-2,j+1});
                if(i-1>0 && j+2<=l) list[i][j].push_back({i-1,j+2});

                if(i+1<=l && j+2<=l) list[i][j].push_back({i+1,j+2});
                if(i+2<=l && j+1<=l) list[i][j].push_back({i+2,j+1});
            }
        }

        queue<pair<int, int>> q;

        q.push(now);
        check[now.first][now.second] = 1;
        int ansi=0, ansj=0;

        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();

            if(f==goal) {
                ansi = f.first;
                ansj = f.second;
                break;
            }
                

            for(int i=0; i<list[f.first][f.second].size(); i++){
                pair<int, int> x = list[f.first][f.second][i];
                if(check[x.first][x.second] == 0){
                    q.push(x);
                    check[x.first][x.second] = check[f.first][f.second]+1;
                }
            }
        }

        cout << check[ansi][ansj] - 1 << '\n';

        for(int i=1; i<=l; i++){
            for(int j=1; j<=l; j++){
                list[i][j].clear();
                check[i][j]=0;
            }
        }

    }
}