//랜선 자르기

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    long long l[k];
    
    for(int i=0; i<k; i++) {
        cin >> l[i];
    }

    sort(l, l+k);

    long long left = 1, right = l[k-1];
    long long mid = right;

    long long maxlen = 0;

    while(left<=right) {
        int cnt = 0;
        for(int i=0; i<k; i++) {
            cnt += l[i]/mid;
        }

        if(cnt>=n) {
            if(maxlen<mid) maxlen = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
        mid = (right+left)/2;
    }

    cout << maxlen << '\n';
}