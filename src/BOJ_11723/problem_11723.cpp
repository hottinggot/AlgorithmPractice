//집합

#include<iostream>

using namespace std;

bool S[21];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        string op;
        int x;
        cin >> op;
        if(op=="add") {
            cin >> x;
            S[x] = 1;
        } else if(op=="remove") {
            cin >> x;
            S[x] = 0;
        } else if(op=="check") {
            cin >> x;
            cout << S[x] << '\n';
        } else if(op=="toggle") {
            cin >> x;
            S[x] = !S[x];
        } else if(op=="all") {
            for(int i=1; i<=20; i++) {
                S[i] = 1;
            }
        } else if(op=="empty") {
            for(int i=1; i<=20; i++) {
                S[i] = 0;
            }
        }
    }
}