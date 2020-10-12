//N과 M (4)

#include<iostream>

using namespace std;

int arr[10];

void go(int n, int m, int index, int start){

    if(index==m) {
        for(int i=0; i<m-1; i++) {
            cout << arr[i] << ' ';
        }
        cout << arr[m-1] << '\n';
        return;
    }

    for(int i=start; i<=n; i++) {
        arr[index] = i;
        go(n,m,index+1,i);
    }

}

int main(){
    int n,m;
    cin >> n >> m;

    go(n,m,0,1);

}