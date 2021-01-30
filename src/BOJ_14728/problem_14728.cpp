//벼락치기

#include<iostream>

using namespace std;

int D[10001];

int main() {
    int n, t;
    cin >> n >> t;
    for(int i=0; i<n; i++) {
        int k,s;
        cin >> k >> s;

        for(int j = t; j>=k ; j--) {
            D[j] = max(D[j], D[j-k]+s);
        }
    }

    for(int i=0; i<n; i++) {
        if(D[i]==0) D[i] = D[i-1];
    }

    cout << D[t] << '\n';
}