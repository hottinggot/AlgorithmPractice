//종이의 개수

#include<iostream>

using namespace std;

int arr[3000][3000];
int cnt[4];

int check(int n, int startx, int starty) {
    int t = arr[startx][starty];
    for(int i=startx; i<startx+n; i++) {
        for(int j=starty; j<starty+n; j++) {
            if(arr[i][j]!=t) {
                return -1;
            }
        }
    }

    return t+1;
}

void devide(int n, int x, int y) {

    if(n==0) return;
    int t = check(n, x, y);
    if(t == -1) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                devide(n/3, x+(n*i)/3, y+(n*j)/3);
            }
        }
        
    } else {
        cnt[t]++;
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

    devide(n,0,0);

    cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';
 }