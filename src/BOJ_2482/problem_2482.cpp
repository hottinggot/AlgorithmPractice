//색상환

#include<iostream>
#include<memory.h>

using namespace std;

int D[1001][1001];


int mod = 1000000003;

int cal(int num, int cnt) {
    if(D[num][cnt] >= 0) return D[num][cnt];
    if(num<0) {
        return 0;
    }
    if(num+1<cnt*2) return 0;
    if(cnt==1) return num;

    D[num][cnt] = (cal(num-2, cnt-1)%mod + cal(num-1, cnt)%mod)%mod;
    
    return D[num][cnt];
}

int main() {
    int n, k;
    cin >> n >> k;

    memset(D, -1, sizeof(D));

    if(n==1 || k==1) cout << n << '\n';
    else if(n==2) cout << 0 << '\n';
    else {
        cout << (cal(n-3, k-1)%mod + cal(n-1, k)%mod)%mod << '\n';
    }

}