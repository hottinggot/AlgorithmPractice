//Four Squares

#include<iostream>
#include<math.h>

using namespace std;

int D[50001];

int INF = 987654321;

int cal(int n) {
    if(D[n]>0) return D[n];
    if(n==0) return 0;

    int temp = INF;
    for(int i=1; i*i<=n; i++) {
        temp = min(temp, 1+cal(n-i*i));
    }
    return D[n] = temp;
}

int main() {
    int n;
    cin >> n;

    cout << cal(n) << '\n';
}