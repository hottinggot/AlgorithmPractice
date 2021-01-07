//K번째 수

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long l = 1;
    long long r = k;
    long long mid = (l+r)/2;

    long long ans = 0;

    while(l<=r) {
        mid = (l+r)/2;

        long long cnt = 0;

        //결정함수: mid보다 작거나 같은 수의 갯수 구하는법.
        for(int i=1; i<=n; i++) {
            cnt+=min(mid/i, n);
        }
        if(cnt >= k){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << '\n';
}