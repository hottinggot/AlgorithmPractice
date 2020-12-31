//동전 0

#include<iostream>
#include<vector>

using namespace std;


int main() {
    int n,k;

    cin >> n >> k;

    vector<int> a;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int sum = 0;

    for(int i=n-1; i>=0; i--) {
        if(k%a[i]==0) {
            sum += k/a[i];
            break;
        }
        if(a[i]<k) {
            int x = k/a[i];
            sum += x;
            k = k-a[i]*x;
        }
    }

    cout << sum << '\n';

}