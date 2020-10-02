//이모티콘

#include<iostream>
#include<queue>

using namespace std;

int check[10001][10001];

int main(){
    int n;
    cin >> n;

    pair<int, int> p;
    queue<pair<int, int>> q;

    p={1,0};
    q.push(p);
    check[1][0] = 1;
    int a1=0, b1=0;
    int a2=0, b2=0;

    while (!q.empty()){
        pair<int, int> f = q.front();
        q.pop();

        if(check[f.first][f.first]==0) {
            pair<int, int> x = {f.first, f.first};
            q.push(x);
            check[x.first][x.second] = check[f.first][f.second] + 1;
        }  

        if(f.second!=0 && f.first + f.second <=1000 && check[f.first+f.second][f.second]==0){
            pair<int, int> x = {f.first + f.second, f.second};
            q.push(x);
            check[x.first][x.second] = check[f.first][f.second] + 1;
        }

        if(f.first-1>=0 && check[f.first-1][f.second]==0){
            pair<int, int> x = {f.first-1, f.second};
            q.push(x);
            check[x.first][x.second] = check[f.first][f.second] + 1;
        }

    }

    int min = 0;

    for(int i=0; i<=n; i++){
        if(check[n][i]!=0) {
            if(min==0 || min>check[n][i]){
                min = check[n][i];
            }
        }
    }

    cout << min-1 << '\n';


}