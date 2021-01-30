//피보나치 수 2

#include<iostream>

using namespace std;

typedef long long ll;

ll D[91];

int main() {
    int n;
    cin >> n;

    D[0] = 0;
    D[1] = 1;
    for(int i=2; i<=n; i++) {
        D[i] = D[i-1] + D[i-2];
    }

    cout << D[n] << '\n';
}