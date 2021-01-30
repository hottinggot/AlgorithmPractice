//파일 합치기

#include <iostream>

using namespace std;

int arr[501];
int D[501][501];
int totalSize[501];

int dp(int start, int end) {
    if(D[start][end]>=0) return D[start][end];
    if(start == end) return 0;
    if(start+1 == end) {
        return arr[start] + arr[end];
    }

    for(int i=start; i<=end; i++) {
        int temp = dp(start, i) + dp(i+1, end) + totalSize[end] - totalSize[start-1];
        if(D[start][end]==-1 || D[start][end]>temp) {
            D[start][end] = temp;
        }
    }

    return D[start][end];
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int k;
        cin >> k;

        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                D[i][j] = -1;
            }
            arr[i] = 0;
            totalSize[i] = 0;

        }

        for(int i=0; i<k; i++) {
            cin >> arr[i];
            totalSize[i] = totalSize[i-1] + arr[i];
        }

        cout << dp(0,k-1) << '\n';
    }
}