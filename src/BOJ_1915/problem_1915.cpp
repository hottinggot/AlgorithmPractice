//가장 큰 정사각형

#include<iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    int D[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &arr[i][j]);
            D[i][j] = arr[i][j];
        }
    }

    for(int k=1; k<=min(n,m); k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(D[i][j] > 0) {
                    //검사
                }

            }
        }
    }
 }