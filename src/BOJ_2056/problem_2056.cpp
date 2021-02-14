//작업

#include<iostream>
#include<vector>

using namespace std;


int t[10001];
vector<int> v[10001];
int D[10001];
bool check[10001];

int cal(int n) {
    if(D[n]>0) return D[n];

    int temp = 0;
    for(int i=0; i<v[n].size(); i++) {
        temp = max(temp, cal(v[n][i]));
    }
    temp += t[n];
    D[n] = temp;
    check[n] = 1;

    return D[n];
}

int main() {
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> t[i];
        int x;
        cin >> x;
        for(int j=0; j<x; j++) {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
    }

    int maxi = 0;
    for(int i=n; i>0; i--) {
        if(check[i]==0) maxi = max(maxi, cal(i));
    }

    cout << maxi << '\n';
}