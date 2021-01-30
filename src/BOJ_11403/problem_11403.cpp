//경로 찾기

#include<iostream>
#include<queue>

using namespace std;

bool path[101][101];
bool check[101];
int n;
bool ans[101][101];

void bfs (int p) {

    for(int i=0; i<n; i++) {
        check[i] = 0;
    }

    queue<int> q;
    q.push(p);

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0; i<n; i++) {
            if(check[i]!=1 && path[f][i]==1){
                q.push(i);
                check[i] = true;
                ans[p][i] = 1;
            }
        }
    }
}

int main() {
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> path[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        bfs(i);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << ' ';

        }
        cout << '\n';
    }

    

}