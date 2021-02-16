//집합의 표현
#include<iostream>

using namespace std;
int parent[1000001];

int find(int node) {

    if(parent[node] == node) {
        return node;
    } else {
        parent[node] = find(parent[node]);
        return parent[node];
    }
}

void uni(int x, int y) {

    int a = find(x);
    int b = find(y);

    if(a!=b) {
        parent[a] = b;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int op, x, y ;

        cin >> op >> x >> y;

        if(op==1) {
            if(find(x) == find(y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            uni(x,y);
        }
    }
}