//스티커

#include<iostream>

using namespace std;
int D[100001][3];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[2][n+1];
        for(int i=1; i<=n; i++) {
            cin >> arr[0][i];
        }
        for(int i=1; i<=n; i++) {
            cin >> arr[1][i];
        }

        D[1][0] = 0;
        D[1][1] = arr[0][1];
        D[1][2] = arr[1][1];

        for(int i=2; i<=n; i++){
            int maximum = D[i-1][0];
            if(D[i-1][1] > maximum) maximum=D[i-1][1];
            D[i][0] = max(maximum, D[i-1][2]);
            D[i][1] = max(D[i-1][0], D[i-1][2]) + arr[0][i];
            D[i][2] = max(D[i-1][0], D[i-1][1]) + arr[1][i];
        }
        int maximum = D[n][0];
        if(D[n][1] > maximum) maximum=D[n][1];
        if(D[n][2] > maximum) maximum=D[n][2];

        cout << maximum << '\n';

    }

}