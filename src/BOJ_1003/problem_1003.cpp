//피보나치 함수

#include<iostream>

using namespace std;

//int cnt[41][2];
pair<int, int> cnt[41];

pair<int, int> fibo(int n) {

    if(cnt[n].first>0 || cnt[n].second>0) return cnt[n];

    if(n==0){
        cnt[n].first++;
    } else if (n == 1) {
        cnt[n].second++;
    } else {
        cnt[n].first = fibo(n-1).first + fibo(n-2).first;
        cnt[n].second = fibo(n-1).second + fibo(n-2).second;
    }
    return cnt[n];
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i=0; i<=n; i++) {
            cnt[i] = {0,0};
        }

        pair<int,int> p = fibo(n);

        cout << p.first << ' ' << p.second << '\n';
    }
}