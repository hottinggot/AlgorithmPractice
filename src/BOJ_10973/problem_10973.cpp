//이전 순열

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    if(prev_permutation(v.begin(), v.end())){
        for(int i=0; i<n-1; i++) {
            cout << v[i] << ' ';
        }
        cout << v[n-1] << '\n';
    } else cout << -1 << '\n';
 
}