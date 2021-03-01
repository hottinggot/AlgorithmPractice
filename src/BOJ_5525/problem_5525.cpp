//IOIOI

#include<iostream>
#include<memory.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string str;
    cin >> str;
    
    int v[m];

    memset(v,0,sizeof(v));

    for(int i=2; i<str.length(); i+=2) {
        if(str[i]=='I' && str[i-2]=='I' && str[i-1]=='O') {
            v[i] = v[i-2]+1;
        }
        else if(i+1<str.length() && str[i]=='O' && str[i-1]=='I' && str[i+1]=='I') {
            v[i+1] = 1;
            i++;
        }
    }

    int cnt = 0;

    for(int i=0; i<str.length(); i++) {
        if(v[i]>=n) {
            cnt++;
        }
    }

    cout << cnt << '\n';

}