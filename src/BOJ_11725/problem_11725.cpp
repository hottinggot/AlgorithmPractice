//트리의 부모 찾기

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> tree[100001];
int check[100001];

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    check[1] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(int i=0; i<tree[f].size(); i++) {
            int x = tree[f][i];

            if(check[x]==0){
                q.push(x);
                check[x] = f;
            }
        }
    }

    for(int i=2; i<=n; i++) {
        cout << check[i] <<'\n';
    }


    
}