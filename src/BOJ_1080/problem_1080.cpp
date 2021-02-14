//행렬

#include<iostream>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    int a[n][m], b[n][m];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &b[i][j]);
        }
    }

    int cnt = 0;

    if(n>=3 && m>=3) {
        for(int i=0; i<n-2; i++) {
            for(int j=0; j<m-2; j++) {
                if(a[i][j]!=b[i][j]) {

                    cnt++;

                    for(int x=i; x<i+3; x++) {
                        for(int y=j; y<j+3; y++) {
                            a[x][y] = (a[x][y]+1)%2;
                        }
                    }

                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j]!=b[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << cnt << '\n';
}