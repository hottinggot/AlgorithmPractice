//소수의 연속합

#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool arr[n+1];
    memset(arr, 1, sizeof(arr));
    arr[0] = 0;
    arr[1] = 0;

    for(int i=2; i<=(n+1)/2; i++) {
        int k = 2;
        if(arr[i]==true) {
            while(i*k<=n) {
                arr[i*k] = false;
                k++;
            }
        } 
    }

    int num = 0;
    vector<int> v;

    for(int i=0; i<=n; i++) {
        if(arr[i]==true) v.push_back(i);
    }

    int s = 0;
    int e = 0;
    int sum = 0;
    int cnt = 0;

    while(1) {

        if(sum>=n) {
            sum-=v[s];
            s++;
        } else if (e==v.size()) break;
        
        else {
            sum+=v[e];
            e++;
        }

        if(sum==n) {
            cnt++;
        }
    }

    cout << cnt << '\n';
}