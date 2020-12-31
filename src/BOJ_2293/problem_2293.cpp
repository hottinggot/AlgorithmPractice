//동전 1

#include<iostream>
#include<algorithm>

using namespace std;

int D[10001];

int main() {
    int n, k;
    cin >> n >> k;

    int cost[101];

    for(int i=1; i<=n; i++) {
        cin >> cost[i];
    }
    
    D[0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j>=cost[i])
                D[j] += D[j-cost[i]]; 
        }
    }

    cout << D[k] <<'\n';
    
}