//안녕

#include<iostream>

using namespace std;

int D[101];

int main() {
    int n;
    cin >> n;

    int sad[n];
    for(int i=0; i<n; i++) {
        cin >> sad[i];
    }

    int happy[n];
    for(int i=0; i<n; i++) {
        cin >> happy[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=100; j>sad[i] ; j--) {
            D[j] = max(D[j], D[j-sad[i]] + happy[i]);
        }
    }

    for(int i=0; i<=100; i++) {
        if(D[i]==0) D[i] = D[i-1];
    }
    cout << D[100] << '\n';
}