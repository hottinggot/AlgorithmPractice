//공유기 설치

#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    int x[n];
    for(int i=0; i<n; i++) {
        cin >> x[i];
    }

    sort(x, x+n);

    int l = x[0];
    int r = x[n-1];
    int mid = (l+r)/2;

    while(l<=r) {
        int cnt = 1;
        int start = x[0];
        for(int i=1; i<n; i++) {
            if(x[i]-start >= mid-x[0]){
                start = x[i];
                cnt++;
            }
        }
        if(cnt>=c){
            l = mid+1;
        } else {
            r = mid-1;
        }

        mid = (l+r)/2;
    }

    cout << mid - x[0] << '\n';

}