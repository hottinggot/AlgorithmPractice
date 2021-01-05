//주유소

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> l;
    vector<int> m;

    long long totalLen = 0;
    for(int i=0; i<n-1; i++) {
        int temp;
        cin >> temp;
        l.push_back(temp);

        totalLen += (long long)temp;
    }

    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        m.push_back(temp);

    }

    long long cost = 0;
    for(int i=0; i<n-1; i++) {
        cost += 1LL*m[i]*l[i];
        totalLen -= l[i];
        for(int j = i+1; ;j++) {
            if(m[i] <= m[j]){
                cost += 1LL*m[i]*l[j];
                totalLen -= l[j];
            } else if(m[i] > m[j] || j==n-1) {
                i = j-1;
                break;
            }
        }
    }

    cout << cost << '\n';

}