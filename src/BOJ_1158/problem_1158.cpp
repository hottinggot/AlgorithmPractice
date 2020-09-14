#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for(int i = 1; i<=n; i++){
        q.push(i);
    }

    int ans[n];
    int p=0;

    while(!q.empty()){
        for(int i = 1; i < k ; i++){ 
            q.push(q.front());
            q.pop();
        }
        ans[p++] = q.front();
        q.pop();
    }

    cout << '<';
    for(int i=0; i<p-1; i++){
        cout << ans[i] << ", ";
    }

    cout << ans[p-1] << ">\n"; 
}