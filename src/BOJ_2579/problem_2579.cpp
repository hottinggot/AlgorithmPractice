//계단 오르기

#include<iostream>

using namespace std;

int cost[301];
int D[301];

int cal(int n){
    if(n<=0) return 0;
    if(D[n]>0) return D[n];

    int tempD1, tempD2;

     tempD1 = cal(n-2) + cost[n];
     tempD2 = cal(n-3) + cost[n-1] + cost[n];

    D[n] = max(tempD1, tempD2);

    return D[n];

}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> cost[i];
    }

     

    cout << cal(n) << '\n';
}