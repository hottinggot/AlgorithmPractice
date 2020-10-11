//포도주 시식

#include<iostream>

using namespace std;

int D[10001];

int main(){
    int n;
    cin >> n;

    int p[n+1];

    for(int i=1; i<=n; i++){
        cin >> p[i];
    }

    D[1] = p[1];
    D[2] = p[1]+p[2];

    for(int i=3; i<=n ;i++) {
        D[i] = D[i-1];
        if(D[i] < D[i-2] + p[i]){
            D[i] = D[i-2] + p[i];
        }
        if(D[i] < D[i-3] + p[i] + p[i-1]){
            D[i] = D[i-3] + p[i] + p[i-1];
        }
    }

    cout << D[n] <<'\n';



}