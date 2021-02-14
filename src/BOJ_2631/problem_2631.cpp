//줄세우기

#include<iostream>
#include<vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    int arr[n];
    int v[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        v[i] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(arr[i]>arr[j] && v[i]-1<v[j]) {
                v[i] = v[j]+1;
            }
        }
    }

    int maxi = 0;
    for(int i=0; i<n; i++) {
        if(v[i]>maxi) maxi = v[i];
    }

    cout << n-maxi << '\n';


}