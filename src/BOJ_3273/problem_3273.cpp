//두 수의 합

#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int x;
    cin >> x;

    int cnt = 0;
    int *s = arr;
    int *e = arr+n-1;
    int sum = *s+*e;

    while(1) {
        if(s==e) break;
        if(sum==x) {
            cnt++;
        }
        if(sum>x) {
            sum = sum-*e+*(e-1);
            e--;
        } else {
            sum = sum-*s+*(s+1);
            s++;
        }
    }
    
    cout << cnt << '\n';
    

}