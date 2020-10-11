//정수 삼각형

#include<iostream>

using namespace std;

int d[501][501];

int main(){
    int n;
    cin >> n;
    int arr[n+1][n+1];
    for(int i=1; i<=n; i++){
       for(int j=1; j<=i; j++){
           cin >> arr[i][j];
       }
    }

    d[1][1] = arr[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                d[i][j] = d[i-1][j] + arr[i][j];
                continue;
            }
            if(j==i){
                d[i][j] = d[i-1][j-1] + arr[i][j];
                continue;
            }
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + arr[i][j];
        }
    }

    int max = d[n][1];
    for(int i=2; i<=n; i++){
        if(d[n][i]> max) max = d[n][i];
    }

    cout << max << '\n';


}