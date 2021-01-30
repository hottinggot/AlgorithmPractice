//앱

#include<iostream>

using namespace std;

int n,m;
int c[101];
int M[101];
int D[101][10001];

int main() {
    
    cin >> n >> m;

    int c[n];
    int M[n];

    for(int i=0; i<n; i++) {
        cin >> M[i];
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> c[i];
        sum += c[i];
    }

    D[0][c[0]] = M[0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=sum ;j++) {
            D[i][j] = D[i-1][j];
             if(j>=c[i]) D[i][j] = max(D[i][j], D[i-1][j-c[i]] + M[i]);
        }
    }

    for(int i=0; i<=sum; i++) {
        if(D[n-1][i]>=m){
            cout << i << '\n';
            break;
        }
    }

}