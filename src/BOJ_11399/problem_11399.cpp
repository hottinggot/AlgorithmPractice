//ATM

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    sort(p.begin(), p.end());

    int sum = 0;
    int alsum = 0;
    for(int i=0; i<p.size(); i++) {
        sum = sum+p[i];
        alsum += sum;
    }

    cout << alsum << '\n';

}