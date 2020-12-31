//트리

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> tree[51];
bool check[51];
bool isRoot[51];

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int p;
        cin >> p;

        if(p!=-1){
            tree[p].push_back(i);
        }
    }

    int d;
    cin >> d;

    queue<int> q;
    q.push(d);
    check[d] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i=0; i<tree[f].size(); i++) {
            int x = tree[f][i];
            if(check[x]==0){
                q.push(x);
                check[x]=1;
            }
        }
    }

    int cnt = 0;
    bool erased = false;

    for(int i=0; i<n; i++) {
        for(int j=0; erased==false && j<tree[i].size(); j++){
            if(tree[i][j]==d){
                tree[i].erase(tree[i].begin()+j);
                erased = true;
                break;
            }
        }
        if(!check[i] && tree[i].size()==0){
            cnt++;
        }
    }

    cout << cnt << '\n';

}