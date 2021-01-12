//1로 만들기 2

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int check[1000001];
int p[1000001];

int main() {
    int n;
    cin >> n;

    queue<int> q;

    q.push(n);
    check[n] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        if(f%3==0 && check[f/3]==0) {
            q.push(f/3);
            check[f/3] = check[f] + 1;
            p[f/3] = f;
            if(f/3==1) break; 
        }
        if(f%2==0 && check[f/2]==0) {
            q.push(f/2);
            check[f/2] = check[f] + 1;
            p[f/2] = f;
            if(f/2==1) break;
        }
        if(f-1>0 && check[f-1]==0) {
            q.push(f-1);
            check[f-1] = check[f] + 1;
            p[f-1] = f;
            if(f-1==1) break;
        }
    }

    cout << check[1]-1 << '\n';

    stack<int> s;
    int index = 1;
    s.push(index);
    while(index!=n) {
        s.push(p[index]);
        index = p[index];
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}