//파도반 수열

#include<iostream>

using namespace std;

long long D[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i=11; i<=n; i++) {
            if(D[i]>0) continue;
            D[i] = D[i-1] + D[i-5];
        }

        cout << D[n] << '\n';

    }
}