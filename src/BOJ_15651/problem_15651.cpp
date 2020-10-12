//N과 M (3)

#include<iostream>

using namespace std;

int arr[10];

void go(int n, int m, int index){
    if(index==m){
        for(int i=0; i<m-1; i++) {
            cout << arr[i] << ' ';
        }
        cout << arr[m-1] << '\n';
        return;
    }

    for(int i=1; i<=n; i++) {
        arr[index] = i;
        go(n, m, index+1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    go(n,m,0);

}