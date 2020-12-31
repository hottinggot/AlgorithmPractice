//최소 스패닝 트리

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> list[10001];
int check[10001];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    for(int i=0; i<e; i++) {
        int x,y,w;
        cin >> x >> y >> w;
        list[x].push_back({y,w});
        list[y].push_back({x,w});
    }

    int mini = -1;

    for(int i=1; i<=v; i++) {

        queue<pair<int, int>> q;
        q.push({i,0}); //root node
        check[i] = 1;

        int a = 0;
        
        while(!q.empty()){
            pair<int, int> f = q.front();
            q.pop();

            int cnt = 0;

            for(int j=0; j<list[f.first].size(); j++) {
                int x = list[f.first][j].first;
                int y = list[f.first][j].second;
                if(check[x]==0 || check[x]>check[f.first]+y){
                    check[x] = check[f.first] + y;

                    q.push({x,y});
                    cnt++;
                }
            }
            if(cnt==0){
                check[f.first]--;
                
                a+=check[f.first];
            }
           
        }

        

        if(mini == -1 || mini>a){
            mini = a;
        }
    

        for(int j=0; j<=v; j++) {
            check[j] = 0;
        }
    }

    cout << mini << '\n';


}