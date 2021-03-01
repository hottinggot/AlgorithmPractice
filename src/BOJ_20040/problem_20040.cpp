//사이클 게임

#include<iostream>

using namespace std;

int parent[500000];

int find(int x) {
    if(parent[x]==x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

bool Union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x==y) return true;
    parent[y] = x;
    return false;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    for(int i=0; i<n; i++) {
        parent[i] = i;
    }

    for(int i=1; i<=m; i++) {
        int x,y;
        cin >> x >> y;
        
        if(Union(x,y)==true) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';

}