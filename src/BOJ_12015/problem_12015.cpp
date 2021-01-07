//가장 긴 증가하는 부분 수열 2

#include<iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int a[n];
    cin >> a[0];
    int index = 0;
    for(int i=1; i<n; i++) {
        int x;
        cin >> x;

        if(x>a[index]){
            a[++index] = x;
        } else {
            int l=0, r=index;
            int mid;
            int ans = 0;
            while(l<=r) {
                mid = (l+r)/2;
                if(x <= a[mid]){
                    ans = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            a[ans] = x;
        }
    }

    cout << index+1 << '\n';
}