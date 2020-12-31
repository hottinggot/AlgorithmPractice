//음하철도 구구팔

#include<iostream>
#include <math.h>

using namespace std;

int gcd(int x, int y) {
    if(y==0) return x;
    else return gcd(y,x%y);
}

int main() {
    int Xstop, Ystop;
    cin >> Xstop >> Ystop;

    int Xnow, Ynow;
    int xv,yv;

    cin >> Xnow >> Ynow >> xv >> yv;

    int g = gcd(xv,yv);
    if(g<0) g = -g;

    xv = xv/g;
    yv = yv/g;

    int dis = -1;
    int minx, miny;

    while(1) {

        if(dis == -1 || pow(Xstop-Xnow, 2) + pow(Ystop-Ynow,2)<dis){
            dis = pow(Xstop-Xnow, 2) + pow(Ystop-Ynow,2);
            minx = Xnow;
            miny = Ynow;
        } else {
            break;
        }

        Xnow = Xnow + xv;
        Ynow = Ynow + yv;
    }

    cout << minx << ' ' << miny << '\n';

}