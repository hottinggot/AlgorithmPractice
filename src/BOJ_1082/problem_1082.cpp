//방 번호

#include<iostream>
#include<algorithm>

using namespace std;

int D[51];

int main() {
    int n; 
    cin >> n;

    int cost[10];
    for(int i=0; i<n; i++) {
        cin >> cost[i];
    }

    //sort(cost, cost+n);

    int k;
    cin >> k;

    string s[k+1];
    for(int i=0; i<=k; i++) {
        s[i] = "";
    }

    for(int i=0; i<=k; i++) {
        for(int j=1; j<n; j++) {
            if(i>=cost[j]) {
                if(D[i]<=D[i-cost[j]]+1) {
                    D[i] = D[i-cost[j]]+1;
                    s[i] = s[i-cost[j]]+(char)('0'+j);
                } 
            }
        }
        // if(i>=cost[0] && D[i]!=0) {
        //     if(D[i]<D[i-cost[0]]+1) {
        //         D[i] = D[i-cost[0]] +1;
        //         s[i] = s[i-cost[0]]+(char)('0');
        //     }
        // }
    }

    for(int i=0; i<=k; i++) {
        cout << i << " : " << s[i] << '\n';
    }

    cout << s[k] << '\n';

}