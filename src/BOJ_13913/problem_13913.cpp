//숨바꼭질 4

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int check[100001];
int p[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    check[n] = 1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        if(f-1>=0 && check[f-1]==0){
            q.push(f-1);
            check[f-1] = check[f] + 1;
            p[f-1] = f;
            if(f-1==k) break;
        }

        if(f+1<=100000 && check[f+1]==0){
            q.push(f+1);
            check[f+1] = check[f] + 1;
            p[f+1] = f;
            if(f+1==k) break;
        }

        if(f*2<=100000 && check[f*2]==0){
            q.push(f*2);
            check[f*2] = check[f] + 1;
            p[f*2] = f;
            if(f*2==k) break;
        }
    }

    cout << check[k]-1 << '\n';

    stack<int> s;
    s.push(k);
    int i = k;
    while(i!=n){
        s.push(p[i]);
        i=p[i];
    }

    while(!s.empty()){
        if(s.size()>1){
            cout << s.top() << ' ';
            s.pop();
        }
        else {
            cout << s.top() << '\n';
            s.pop();
        }
    }
    
}