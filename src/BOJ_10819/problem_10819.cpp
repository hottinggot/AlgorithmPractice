//차이를 최대로

#include<iostream>
#include<vector>
#include<algorithm>

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

    sort(v.begin(), v.end());

    int max=0;

    do{
        int sum=0;
        for(int i=0; i<n-1; i++) {
            sum += abs(v[i]-v[i+1]);
        }
        if(max==0 || sum > max) max = sum;
    } while(next_permutation(v.begin(), v.end()));

    cout << max << '\n';


}