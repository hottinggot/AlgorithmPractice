//사탕 가게

#include<iostream>

using namespace std;

int D[10001];
int C[5001];
int P[5001];
int n;

int dfs(int m) {

    if(D[m]>0) return D[m];
    if(m<0) return 0;

    for(int i=0; i<n; i++) {
        if(m>=P[i]) D[m] = max(D[m], dfs(m-P[i])+C[i]);
    }
    return D[m];
}

int main() {

    while(1) {
        double m;
        cin >> n >> m;

        

        if(n==0 && m==0) break;

        int tempM = (int)(m*100 + 0.5);

        for(int i=0; i<n; i++) {
            int c;
            double p;
            cin >> c >> p;

            C[i] = c;
            P[i] = (int)(p*100 + 0.5);
        }

        cout << dfs(tempM) << '\n';

        for(int i=0; i<n; i++) {
            C[i] = 0;
            P[i] = 0;
        }
        for(int i=0; i<=tempM; i++) {
            D[i] = 0;
        }

    }

}