#include<iostream>
#include<math.h>
using namespace std;

typedef long long ll;
int r,c;
ll cnt=0;
bool flag = 0;

void cal(int x, int y, int len) {

    if(r>=x && r<x+len && c>=y && c<y+len) {
        if(len==1) {
            flag=1;
            return;
        }
        cal(x,y,len/2);
        cal(x,y+len/2, len/2);
        cal(x+len/2,y,len/2);
        cal(x+len/2,y+len/2,len/2); 
    } else {
        if(flag==0) cnt+=len*len;
    }

}
int main() {
    int n;
    cin >> n >> r >> c;
    cal(0,0,pow(2,n));

    cout << cnt << '\n';

}