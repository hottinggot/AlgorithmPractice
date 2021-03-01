//RGB거리 2

#include<iostream>

using namespace std;

int INF = 1000001;

struct cost {
    int r;
    int g;
    int b;
};

cost arr[1001];
int D[1001][1001];

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> arr[i].r >> arr[i].g >> arr[i].b;
    }

    int minval = -1;

    D[1][0] = arr[1].r;
    D[1][1] = INF;
    D[1][2] = INF;

    for(int i=2; i<n; i++) {
        D[i][0] = min(D[i-1][1],D[i-1][2]) + arr[i].r;
        D[i][1] = min(D[i-1][0],D[i-1][2]) + arr[i].g;
        D[i][2] = min(D[i-1][0],D[i-1][1]) + arr[i].b;
    }

    D[n][1] = min(D[n-1][0],D[n-1][2]) + arr[n].g;
    D[n][2] = min(D[n-1][0],D[n-1][1]) + arr[n].b;

    if(minval==-1 || minval>D[n][1]) minval = D[n][1]; 
    if(minval==-1 || minval>D[n][2]) minval = D[n][2]; 

    D[1][0] = INF;
    D[1][1] = arr[1].g;
    D[1][2] = INF;

    for(int i=2; i<n; i++) {
        D[i][0] = min(D[i-1][1],D[i-1][2]) + arr[i].r;
        D[i][1] = min(D[i-1][0],D[i-1][2]) + arr[i].g;
        D[i][2] = min(D[i-1][0],D[i-1][1]) + arr[i].b;
    }

    D[n][0] = min(D[n-1][1],D[n-1][2]) + arr[n].r;
    D[n][2] = min(D[n-1][0],D[n-1][1]) + arr[n].b;

    if(minval==-1 || minval>D[n][0]) minval = D[n][0]; 
    if(minval==-1 || minval>D[n][2]) minval = D[n][2]; 

    D[1][0] = INF;
    D[1][1] = INF;
    D[1][2] = arr[1].b;

    for(int i=2; i<n; i++) {
        D[i][0] = min(D[i-1][1],D[i-1][2]) + arr[i].r;
        D[i][1] = min(D[i-1][0],D[i-1][2]) + arr[i].g;
        D[i][2] = min(D[i-1][0],D[i-1][1]) + arr[i].b;
    }

    D[n][0] = min(D[n-1][1],D[n-1][2]) + arr[n].r;
    D[n][1] = min(D[n-1][0],D[n-1][2]) + arr[n].g;

    if(minval==-1 || minval>D[n][0]) minval = D[n][0]; 
    if(minval==-1 || minval>D[n][1]) minval = D[n][1]; 

    cout << minval << '\n';
   
}