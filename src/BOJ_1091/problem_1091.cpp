//카드 섞기

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int P[n];
    for(int i=0; i<n; i++) {
        cin >> P[i];
    }

    int S[n];
    for(int i=0; i<n; i++) {
        cin >> S[i];
    }

    int temp[n];
    for(int i=0; i<n; i++) {
        temp[i] = i;
    }

    int z = 0;
    for(int i=0; i<n; i++) {
        if(i%3 == P[i]) z++;
    }
    if(z==n) {
        cout << 0 << '\n';
        return 0;
    }

    int num = 0;
    while(1) {
        for(int i=0; i<n; i++) {
            temp[i] = S[temp[i]];
        }
        num++;

        int p=0;
        for(int i=0; i<n; i++) {
            if(temp[i]==i) p++;
        }
        if(p==n) {
            cout << -1 << '\n';
            return 0;
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(temp[i]%3!=P[i]) break;
            else cnt++;
        }
        if(cnt==n) break;
    }

    cout << num << '\n';
    
}