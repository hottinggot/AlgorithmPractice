//두 용액 

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int *sp = arr;
    int *ep = arr+n-1;

    int sum = *sp+*ep;
    int temp1 = *sp, temp2 = *ep;
    int minsum = temp1+temp2;

    while(1) {
        if(sum==0) {
            temp1 = *sp;
            temp2 = *ep;
            break;  
        }
        else if(sum>0) {
            sum = sum-*ep+*(ep-1);
            ep--;
        } else {
            sum = sum-*sp+*(sp+1);
            sp++;
        }
        if(sp==ep) break;
        if(abs(minsum)>abs(sum)) {
            temp1 = *sp;
            temp2 = *ep;
            minsum = temp1+temp2;
        }
    }

    cout << temp1 << ' ' << temp2 << '\n';
}