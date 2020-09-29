//이분 그래프

#include<iostream>
#include<vector>

using namespace std;

vector<int> list[20001];
int color[20001];

void dfs(int x, int c){
    color[x] = c;

    for(int i=0; i<list[x].size(); i++){
        int y = list[x][i];
        if(color[y]==0){
            dfs(y,3-c);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    while(k--){

        int v,e;
        cin >> v >> e;

        for(int i=0; i<=v; i++){
            color[i] = 0;
            list[i].clear();
        }

        while(e--){
            int from, to;

            cin >> from >> to;
            list[from].push_back(to);
            list[to].push_back(from);
        }

        for(int i=1; i<=v; i++){
            if(color[i]==0) dfs(i,1);
        }
        
        bool yn = true;

        for(int i=1; i<=v; i++){
            for(int j=0; j<list[i].size(); j++){
                int k = list[i][j];
                if(color[i]==color[k]) {
                    yn = false;
                    break;
                }
            }
            if(!yn) break;
        }
        
        if(yn) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        

    }
}