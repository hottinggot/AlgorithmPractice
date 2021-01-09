//쿼드트리

#include<iostream>

using namespace std;

int arr[65][65];

int check(int n, int startx, int starty){
    int temp = arr[startx][starty];
    for(int i=startx; i<startx+n; i++){
        for(int j=starty; j<starty+n; j++) {
            if(temp!=arr[i][j]) return -1;
        }
    }
    return temp;
}

void quardTree(int n, int x, int y) {
    if(n==0) return;

    int t = check(n, x, y);
    if(t==-1) {
        cout << '(';
        quardTree(n/2, x, y);
        quardTree(n/2, x, y+n/2);
        quardTree(n/2, x+n/2, y);
        quardTree(n/2, x+n/2, y+n/2);
        cout << ')';
    } else {
        cout << t ;
    }

}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%1d", &arr[i][j]) ;
        }
    }
    quardTree(n,0,0);
}