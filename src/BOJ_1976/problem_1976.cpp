//여행 가자

#include<iostream>

using namespace std;

int parent[201];

int find (int x) {
    if(parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);

    parent[y] = x;
}

int main() {
    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    int map[n+1][n+1];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> map[i][j];
            if(map[i][j]==1) {
                Union(i,j);
            }
        }
    }

    int temp = -1;
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;

        if(temp==-1) temp = find(x);
       
        else {
            if(temp!=find(x)) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

}