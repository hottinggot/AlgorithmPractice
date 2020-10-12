//모든 순열

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for(int i=1; i<=n; i++) {
        v.push_back(i);
    }

    do{
        for(int i=0; i<n-1; i++){
            cout << v[i] << ' ';
        }
        cout << v[n-1] << '\n';
    } while(next_permutation(v.begin(), v.end()));
}