//케빈 베이컨의 6단계 법칙

#include<iostream>

using namespace std;

int INF = 1000;

int main() {
    int n,m;
    cin >> n >> m;

    int arr[n+1][n+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++) {
        int x,y;
        cin >> x >> y;

        arr[x][y] = 1;
        arr[y][x] = 1;
    }


    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {   
                if(arr[i][k]!=INF && arr[k][j]!=INF) {
                    if(arr[i][j]>arr[i][k]+arr[k][j]) {
                        arr[i][j] = arr[i][k]+arr[k][j];
                    }
                }
            }
        }
    }

    int mini = INF;
    int minIdx;
    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=1; j<=n; j++) {
            sum += arr[i][j];
        }
        if(mini>sum) {
            mini = sum;
            minIdx = i;
        }        
    }

    cout << minIdx << '\n';

}