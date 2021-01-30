//팰린드롬?

#include<iostream>

using namespace std;

int num[2001];
int D[2001][2001];

int dp(int start, int end) {
    if(D[start][end] != 0) return D[start][end];
    if(start==end) return 2;
    if(end<start) return 2;
    if(num[start]!=num[end]) {
        D[start][end] = 1;
    } else {
        D[start][end] = dp(start+1, end-1);
    }

    return D[start][end];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    
    for(int i=1; i<=n; i++) {
        cin >> num[i];
    }

    int m;
    cin >> m;

    while (m--)
    {

        int s,e;
        cin >> s >> e;

        cout << dp(s,e)-1 << '\n';
    }
    
}