//ABCDE

#include<iostream>
#include<vector>

using namespace std;

vector<int> list[2000]; //인접리스트
bool arr[2000][2000];  //인접행렬
vector<pair<int, int>> edges; //간선리스트

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<m;i++){
        int a, b;
        cin >> a >> b;

        //간선리스트
        edges.push_back({a,b});
        edges.push_back({b,a});

        //인접행렬
        arr[a][b] = true;
        arr[b][a] = true;

        //인접리스트
        list[a].push_back(b);
        list[b].push_back(a);
    }

    m=m*2;

    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++){
            int A = edges[i].first;
            int B = edges[i].second;

            int C = edges[j].first;
            int D = edges[j].second;

            if(A==B || A==C || C==D || A==D || B==D || B==C) {
                continue;
            }

            if(arr[B][C] != true) continue;

            for(int E: list[D]){
                if(A==E || B==E || C==E || D==E) continue;

                cout << 1 << '\n';
                return 0;
            }
        }

    }

    cout << 0 << '\n';
    return 0;

}