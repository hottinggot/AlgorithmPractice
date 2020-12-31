//타일 채우기

#include<iostream>

using namespace std;

int d[31];

int main() {
    int n;
    cin >> n;

    d[0] = 1;

    for(int i=2; i<=n; i+=2) {
        d[i] += d[i-2]*3;
        for(int j=4; j<=i; j+=2) {
            d[i] += d[i-j]*2;
        }
    }

    cout << d[n] << '\n';
}