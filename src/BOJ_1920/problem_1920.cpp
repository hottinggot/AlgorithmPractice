//수 찾기

#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    long long a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int m;
    cin >> m;

    for(int i=0; i<m; i++) {
        int k;
        cin >> k;

        int l = 0;
        int r = n;
        int mid = (l+r)/2;

        int flag = 0;

        while(l<=r) {
            if(k==a[mid]) {
                flag = 1;
                break;
            } else if(k<a[mid]) {
                r = mid-1;
                mid = (r+l)/2;
            } else {
                l = mid+1;
                mid = (r+l)/2;
            }
        }

        cout << flag << '\n';

    }
}