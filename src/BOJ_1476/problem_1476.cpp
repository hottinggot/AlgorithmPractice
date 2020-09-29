//날짜 계산

#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int e, s, m;
    cin >> e >> s >> m ;

    e=e-1;
    s=s-1;
    m=m-1;

    int i=0;
    while(1){
        if(i%15==e && i%28==s && i%19==m) break;
        i++;
    }

    cout << i+1 << '\n';
}