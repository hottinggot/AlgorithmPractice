//숨바꼭질

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int check[100001];

int main(){
    int n,k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    check[n] = 1;

    while(!q.empty()) {
        int f = q.front();
        q.pop();

        if(f-1>=0) {
            int x = f-1;
            if(check[x]==0){
                q.push(x);
                check[x] = check[f] + 1;
                if(x==k) break;
            }
        }

        if(f+1<=100000) {
            int x = f+1;
            if(check[x]==0){
                q.push(x);
                check[x] = check[f] + 1;
                if(x==k) break;
            }
        }

        if(f*2<=100000) {
            int x = f*2;
            if(check[x]==0){
                q.push(x);
                check[x] = check[f] + 1;
                if(x==k) break;
            }
        }
    }

    cout << check[k]-1 << '\n';

}