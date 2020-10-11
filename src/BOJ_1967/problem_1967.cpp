//트리의 지름

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> tree[10001];
int check[10001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v;
    cin >> v;

    for(int i=1; i<v; i++){
        int k, x, y;

        cin >> k >> x >> y;
        tree[k].push_back({x,y});
        tree[x].push_back({k,y});
    }

    queue<pair<int, int>> q;

    q.push({1,0});
    check[1] = 1;

    while(!q.empty()){
        pair<int, int> f = q.front();
        q.pop();

        for(int i=0; i<tree[f.first].size(); i++) {
            pair<int, int> x = tree[f.first][i];
            if(check[x.first]==0){
                q.push(x);
                check[x.first] = check[f.first] + x.second;
            }
        }
    }

    int max1=0;
    int check_max1=0;
    for(int i=1; i<=v; i++){
        if(check[i]>check_max1 || check_max1==0) {
            check_max1 = check[i];
            max1=i;
        }
        check[i]=0;
    }

    q.push({max1, 0});
    check[max1] = 1;

    while(!q.empty()){
        pair<int, int> f = q.front();
        q.pop();

        for(int i=0; i<tree[f.first].size(); i++) {
            pair<int, int> x = tree[f.first][i];
            if(check[x.first]==0){
                q.push(x);
                check[x.first] = check[f.first] + x.second;
            }
        }
    }

    int check_max2=check_max1;
    for(int i=1; i<=v; i++){
        if(check[i]>check_max2) {
            check_max2=check[i];
        }
    }


    cout <<check_max2-1<< '\n';
}