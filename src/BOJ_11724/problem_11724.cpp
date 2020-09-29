//연결 요소의 개수

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> list[1001];
bool check[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;

        list[u].push_back(v);
        list[v].push_back(u);
    }

    queue<int> q;
    int k=1;
    int cnt = 0;

    while(k<=n){

        q.push(k);
        check[k] = true;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=0; i<list[x].size(); i++) {
                int y = list[x][i];
                if(!check[y]){
                    q.push(y);
                    check[y] = true;
                }
            }
        }

        cnt++;

        for(int i=k;i<=n;i++){
            if(!check[i]){
                k=i;
                break;
            }
            k=n+1;
        }

    }
    
    cout << cnt << '\n';

}