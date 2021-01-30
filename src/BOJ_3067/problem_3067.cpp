//Coins

#include<iostream>

using namespace std;

int money[21];
int D[10001];
int n;

int main() {
    int t;
    cin >> t;

    while(t--) {

        cin >> n;

        for(int i=0; i<=10000; i++) {
            D[i] = 0;
        }
        
        for(int i=0; i<n; i++) {
            cin >> money[i];
        }

        int m;
        cin >> m;

        D[0] = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<=m; j++) {
                if(j>=money[i]) D[j] += D[j-money[i]];
            }
        }

        cout << D[m] << '\n';
    }
    
}