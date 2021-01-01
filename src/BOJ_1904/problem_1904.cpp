//01타일

#include<iostream>

using namespace std;

int D[1000001];

int btile(int n) {
    if(D[n] > 0) return D[n];
    if(n<0) return 0;
    if(n==0 || n==1) return 1;

    D[n] = (btile(n-1)%15746 + btile(n-2)%15746)%15746;

    return D[n];
}
int main() {
    int n;
    cin >> n;

    cout << btile(n) << '\n';
}