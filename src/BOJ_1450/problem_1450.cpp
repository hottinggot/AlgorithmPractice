//냅색문제

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll sum = 0;

void bt(vector<int> a, int index, int n, int c, vector<ll> &v) {

    if(sum>c) return;
    if(index==n) {
        v.push_back(sum);
        return;
    }

    sum+=a[index];
    bt(a, index+1, n, c, v);
    sum-=a[index];
    bt(a, index+1, n, c, v);
}

int main() {
    int n,c;
    cin >> n >> c;

    vector<int> a1;
    vector<int> a2;
    for(int i=0; i<(n+1)/2; i++) {
        int x;
        cin >> x;
        a1.push_back(x);
    }
    for(int i=(n+1)/2; i<n; i++) {
        int x;
        cin >> x;
        a2.push_back(x);
    }


    vector<ll> v1, v2;

    sum = 0;
    bt(a1, 0, a1.size(), c, v1);
    sort(v1.begin(), v1.end());

    sum = 0;
    bt(a2, 0, a2.size(), c, v2);
    sort(v2.begin(), v2.end());

    int cnt = 0;

    int p1 = 0;
    int p2 = v2.size()-1;
    ll s = v1[p1] + v2[p2];

    while(1) {

        if(s>c) {
            s = s-v2[p2]+v2[p2-1];
            p2--;
        } 

        if(p1==v1.size() || p2<0) break;

        if(s<=c) {
            cnt+=p2+1;
            s = s-v1[p1] + v1[p1+1];
            p1++;
        }
    }

    cout << cnt << '\n';
    
}