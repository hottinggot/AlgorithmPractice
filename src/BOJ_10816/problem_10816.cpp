//숫자 카드 2

#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int m;
    cin >> m;

    for(int i=0; i<m; i++) {
        int k;
        cin >> k;

        int cnt = 0;

        cnt = upper_bound(a, a+n, k) - lower_bound(a, a+n, k);
        cout << cnt << ' ';
    }
}