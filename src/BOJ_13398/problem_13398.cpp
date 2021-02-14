//연속합 2

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int v[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        v[i] = arr[i];
    }

    for(int i=1; i<n; i++) {
        if(v[i-1]+arr[i]>arr[i]) {
            v[i] = v[i-1] + arr[i];           
        }
    }

    int maxi = 0;
    for(int i=0; i<n; i++) {
        //cout << v[i] << ' ';
        if(v[i]>maxi) {
            maxi = v[i];
        }
    }

    int temp = 0;
    int maxval = 0;
    int maxsum = maxi;
    for(int i=1; i<n; i++) {
        //maxval을 이런 식으로 구하면 안됨.
        if(maxval<v[i]) {
            maxval = v[i];
        }
        if(arr[i]<0 || i==n-1) {
            cout << temp << ' ' << maxval << '\n';
            if(maxsum<temp+maxval) maxsum = temp+maxval;
            temp = v[i-1];
            maxval = 0;
        }    
    }

    cout << maxsum << '\n';

}