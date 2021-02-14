//수 묶기

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }

    sort(v.begin(), v.end());

    int sum = 0;

    for(int i=0; i<v.size() && v[i]<0; i++) {
        if(i+1<v.size() && v[i]*v[i+1]>0) {
            sum+=v[i]*v[i+1];
            i++;
        }
        else if(i==v.size()-1) sum+=v[i];
        else if(v[i]*v[i+1]<0) sum+=v[i];
    }

    for(int i=v.size()-1; i>=0 && v[i]>0; i--) {
        if(i-1>=0 && v[i]*v[i-1]>0 && v[i]*v[i-1]>v[i]+v[i-1]) {
            sum+=v[i]*v[i-1];
            i--;
        } else if(i==0) {
            sum+=v[i];
        }
        else {
            sum+=v[i];
        }
    }

    cout << sum << '\n';
}