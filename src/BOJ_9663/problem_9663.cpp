//N-Queen

#include<iostream>

using namespace std;

int c;

int go(int x, int n, bool (*chess)[16]){
    if(x>=n) {
        c++;
        return 0;
    }

    bool temp[16][16];

    int cnt=0;

    for(int k=0; k<n;k++) {
        if(chess[x][k]==0){
            cnt++;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    temp[i][j] = chess[i][j];
                    if(i==x || j==k || j-i == k-x || i+j==k+x){
                        temp[i][j] = 1;
                    }
                }
            }
            go(x+1, n, temp);
        }
    }

    if(cnt==0) return 0;

}

int main() {
    int n;
    cin >> n;

    bool chess[16][16];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            chess[i][j]=0;
        }
    }

    go(0,n,chess);
    cout << c << '\n';

    
}