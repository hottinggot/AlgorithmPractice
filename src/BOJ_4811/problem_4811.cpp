//알약

#include<iostream>

using namespace std;

typedef long long ll;
ll D[31][61]; //n, 반쪽알약

ll cal(int full, int half) {
    if(D[full][half]>0) return D[full][half];
    if(full==0 && half==0) return 1;

    ll temp = 0;
    if(half>0) {
        temp += cal(full, half-1);
    }

    if(full>0) {
        temp += cal(full-1, half+1);
    }

    D[full][half] = temp;

    return D[full][half];
}
int main() {
    while(1) {
        int n;
        cin >> n;

        if(n==0) break;

        cout << cal(n,0) << '\n';
    }
}