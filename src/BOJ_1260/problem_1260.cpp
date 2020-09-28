//DFS와 BFS

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> list[1001];
bool check1[1001];
bool check2[1001];


void dfs(int v){
    check1[v] = true;
    cout << v ;

    for(int i=0; i<list[v].size(); i++){
        int t = list[v][i];
        if(!check1[t]) {
            cout << ' ';
            dfs(t);
        }
    }   
}

void bfs(int v){
    queue<int> q;
    check2[v] = true;
    cout << v;

    q.push(v);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<list[x].size(); i++){
            int y = list[x][i];
            if(!check2[y]){
                cout << ' ';
                q.push(y);
                check2[y] = true;
                cout<< y;
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,v;
    cin >> n >> m >> v;

    for(int i = 1; i<=m; i++){
        int from, to;
        cin >> from >> to;

        list[from].push_back(to);
        list[to].push_back(from);
    }

    for(int i=1;i<=n && !list[i].empty();i++)
        sort(list[i].begin(), list[i].end());

    dfs(v);
    cout << '\n';

    bfs(v);
    cout << '\n';

}