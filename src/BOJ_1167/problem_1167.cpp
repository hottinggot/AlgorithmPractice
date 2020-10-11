//트리의 지름

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> tree[100001];
int check[100001];

int main(){
    int v;
    cin >> v;

    for(int i=0; i<v; i++){
        int k;
        int x=0, y=0;

        cin >> k; 

        while(1){
            cin >> x;
            if(x==-1) break;
            cin >> y;
            tree[k].push_back({x,y});
        }
    }

    queue<pair<int, int>> q;

    q.push(tree[1][0]);
    check[tree[1][0].first] = 1;

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
        if(check_max1==0 || check[i]>check_max1) {
            max1=i;
            check_max1=check[i];
        }
        check[i]=0;
    }
    check_max1--;

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

    int check_max2=0;
    for(int i=1; i<=v; i++){
        if(check_max2==0 || check[i]>check_max2) {
            check_max2=check[i];
        }
    }
    check_max2--;



    cout <<check_max2<< '\n';
}