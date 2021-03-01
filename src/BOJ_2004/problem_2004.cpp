//조합 0의 개수
#include<iostream>

using namespace std;

typedef long long ll;

int main() {
    int n,m;
    cin >> n >> m;

    int cnt2 = 0;
    int cnt5 = 0;

    ll k=2;
    ll l=5;

    while(l<=n) {
        cnt5+=n/l;
        l=l*5;
    }
    while(k<=n) {
        cnt2+=n/k;
        k=k*2;
    }

    int temp2 = cnt2;
    int temp5 = cnt5;

    cnt2=0;
    cnt5=0;
    l=5;
    k=2;
    while(l<=m) {
        cnt5+=m/l;
        l=l*5;
    }
    while(k<=m) {
        cnt2+=m/k;
        k=k*2;
    }

    temp2-=cnt2;
    temp5-=cnt5;

    cnt2=0;
    cnt5=0;
    l=5;
    k=2;

    while(l<=n-m) {
        cnt5+=(n-m)/l;
        l=l*5;
    }
    while(k<=n-m) {
        cnt2+=(n-m)/k;
        k=k*2;
    }

    temp2-=cnt2;
    temp5-=cnt5;

    cout << min(temp2, temp5) << '\n';
}