//신나는 함수 실행

#include<iostream>

using namespace std;

int D[21][21][21];

int w(int a, int b, int c) {


    if(a<=0 || b<=0 || c<=0) {
        return 1;
    }

    if(a<=20 && b<=20 && c<=20 && D[a][b][c]>0) return D[a][b][c];

    if(a>20 || b>20 || c>20) {
        D[20][20][20] = w(20, 20, 20);
        return D[20][20][20];
    }

    if(a<b && b<c) {
        D[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return D[a][b][c];
    }

    D[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return D[a][b][c];
}

int main() {
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a==-1 && b==-1 && c==-1) break;

        int temp = w(a,b,c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << temp <<'\n';
    }
    
}