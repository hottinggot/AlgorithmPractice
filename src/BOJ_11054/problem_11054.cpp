//가장 긴 바이토닉 부분 수열

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    int inc[n];
    int dec[n];

    for(int i=0; i<n; i++) {
        inc[i] = 1;
        dec[i] = 1;
    }

    for(int i=0; i<n; i++) {
        cin >> a[i];
        for(int j=i-1; j>=0; j--){
            if(a[i]>a[j] && inc[i]-1<inc[j]) {
                inc[i] = inc[j] + 1;
            }
        }
    }

    int maxi = 0;

    for(int i=n-1; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            if(a[i]>a[j] && dec[i]-1<dec[j]) {
                dec[i] = dec[j] + 1;
            }
        }

        if(inc[i]+dec[i]-1 > maxi) maxi = inc[i]+dec[i]-1;
    }

    cout << maxi << '\n';

}