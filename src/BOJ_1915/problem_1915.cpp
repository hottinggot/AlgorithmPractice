//가장 큰 정사각형

#include<iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    int D[n][m];

    int maxsize = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &arr[i][j]);
            D[i][j] = arr[i][j];
            if(D[i][j]==1) maxsize=1;
        }
    }

    if(maxsize==0) {
        cout << 0 << '\n';
        return 0;
    }

    int size = 1;

    while(1) {
        if(size==n || size==m) break;

        bool flag = 0;
        for(int i=0; i<n-size; i++) {
            for(int j=0; j<m-size; j++) {
                if(D[i][j]==1 && D[i+1][j]==1 && D[i][j+1]==1 && D[i+1][j+1]==1) {
                    D[i][j] = 1;
                    flag = 1;
                } else D[i][j] = 0;
            }
        }
        if(flag==1) maxsize++;
        size++;
    }
    
    cout << maxsize*maxsize << '\n';
 }