//전깃줄

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> list;
    int v[n];

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        list.push_back({a,b});
        v[i] = 1;
    }

    sort(list.begin(), list.end());

    int vmax = 1;
    
    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(list[i].second > list[j].second){
                if(v[j]>v[i]-1) v[i] = v[j]+1;
            }
            if(v[i] > vmax) vmax = v[i];
        }
    }

    cout << n-vmax << '\n';
}