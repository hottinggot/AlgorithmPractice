//양팔저울

#include<iostream>
#include<vector>

using namespace std;

vector<int> w;
int D[31][15001];

int dp(int index, int n) {
    if(n>15000) return 1;
    if(D[index][n]>0) return D[index][n];
    if(index>=w.size()) return 1;
    if(w[index]==n) {
        return 2;
    }
    int temp = dp(index+1, n+w[index]);
    int temp2 = dp(index+1, n);
    int temp3 = dp(index+1, n-w[index]);

    if(temp==2 || temp2==2 ||temp3==2) {
        D[index][n] = 2;
    }
    else D[index][n] = 1;

    return D[index][n];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        w.push_back(x);
        sum += x;
    }

    int k;
    cin >> k;

    int g;
    for(int i=0; i<k; i++) {
        cin >> g;
        if(n==sum) cout << 'Y' <<' ';
        else {
            if(dp(0,g)==2) cout << 'Y' << ' ';
            else cout << 'N' <<' ';
        }
    }
}