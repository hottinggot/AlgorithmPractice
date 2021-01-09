//색종이 만들기

#include<iostream>

using namespace std;

int arr[130][130];
int color[2];

int check(int startx, int endx, int starty, int endy){
    int t = arr[startx][starty];
    for(int i=startx; i<endx; i++) {
        for(int j=starty; j<endy; j++){
            if(t!=arr[i][j]) return -1;
        }
    }
    return t;
}

void devide(int n, int x, int y) {
    
    if(n==0) return;

    int t = check(x,x+n,y,y+n);
    if(t==-1){
        devide(n/2, x, y);
        devide(n/2, x+n/2, y);
        devide(n/2, x, y+n/2);
        devide(n/2, x+n/2, y+n/2);
    } else {
        color[t]++;
    }

}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int t;
    devide(n,0,0);
    
    cout << color[0] << '\n' << color[1] << '\n';
}