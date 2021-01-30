//행렬 곱셈 순서

#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> v;
int D[501][501];

int dp(int start, int end) {
    if(D[start][end]>=0) return D[start][end];
    if(start == end) return 0;
    if(start+1 == end) {
        return v[start].first * v[start].second * v[end].second;
    }

    for(int i = start; i<=end; i++) {
        int temp = dp(start, i) + dp(i+1, end) + v[start].first * v[i].second * v[end].second;
        if(D[start][end]==-1 || D[start][end]>temp) D[start][end] = temp;
    }

    return D[start][end];
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            D[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++) {
        int r,c;
        cin >> r >> c;
        v.push_back({r,c});
    }

    cout << dp(0, n-1) << '\n';
}