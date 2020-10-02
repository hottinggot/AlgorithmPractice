//숨바꼭질 3

#include<iostream>
#include<queue>

using namespace std;

int check[100001];

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q1; //0초
    queue<int> q2; //1초

    q1.push(n);
    check[n]=1;

    while(!q1.empty()){
        while(!q1.empty()){
            int f1 = q1.front();
            q1.pop();

            if(f1*2 <=100000 && check[f1*2]==0){
                q1.push(f1*2);
                check[f1*2] = check[f1];
            }

            if(f1+1 <=100000 && check[f1+1]==0){
                q2.push(f1+1);
                check[f1+1] = check[f1] + 1;
            }

            if(f1-1>=0 && check[f1-1]==0) {
                q2.push(f1-1);
                check[f1-1] = check[f1] + 1;
            }

            if(check[k]>0) break;
        }

        if(check[k]>0) break;

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
    }

    cout << check[k]-1 << '\n';

    
}