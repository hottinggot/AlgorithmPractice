//나무 자르기
//long long 때문에 틀림

#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long namu[n];
    for(int i=0; i<n; i++) {
        cin >> namu[i];
    }

    sort(namu, namu + n);

    long long l = 0; 
    long long r = namu[n-1];
    long long mid = (r+l)/2;

    while(l<=r) {
        long long total = 0;
        for(int i=0; i<n; i++) {
            if(namu[i]-mid>0) total+=(namu[i]-mid);
        }

        if(total>=m) {
            l = mid+1;
        } else
        {
            r = mid-1;
        }
        mid = (r+l)/2;
    }

    cout << mid << '\n';
}