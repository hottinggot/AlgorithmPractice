//1학년

#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

typedef long long ll;

vector<int> v;
ll D[101][21];

ll dp(int index, int n) {
    if(D[index][n]!=-1) return D[index][n];
    if(index == 0) {
        if(n==v[0]) return 1;
        else return 0;
    }
    
    ll temp = 0;
    if(n-v[index]>=0) {
        temp += dp(index-1, n-v[index]);
    }
    if(n+v[index]<=20) {
        temp += dp(index-1, n+v[index]);
    }
    D[index][n] = temp;

    return D[index][n];
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    memset(D, -1, sizeof(D));
    cout << dp(n-2,v[n-1]) << '\n';
}