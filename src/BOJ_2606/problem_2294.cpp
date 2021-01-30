//동전 2

#include<iostream>
#include<algorithm>

using namespace std;

int D[10001];

int main() {
    int n,k;
    cin >> n >> k;

    int v[n];
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v, v+n);

    for(int i=1; i<=k; i++) D[i] = -1;

    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(j>=v[i] && D[j-v[i]]!=-1) {
                if(D[j]==-1 || D[j]>D[j-v[i]]+1) D[j] = D[j-v[i]]+1;
            }
        }
    }

    cout << D[k] << '\n';

}