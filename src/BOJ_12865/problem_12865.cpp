//평범한 배낭

#include<iostream>

using namespace std;

int D[100001];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int w, v;
        cin >> w >> v;

        for(int j=k; j>=w; j--) {
            D[j] = max(D[j], v + D[j-w]);
        }
    }

    for(int i=1; i<=k; i++) {
        if(D[i]==0) D[i] = D[i-1];
    }

    cout << D[k] << '\n';
}