//조합 0의 개수
////////
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin >> n >> m ;

    if(n/2<m) m=n-m;

    int a2=0, a5=0;
    int b2=0, b5=0;

    for(long long i = n-n%2; i>n-m ; i-=2){
        a2++;
    }

    for(long long i = n-n%5; i>n-m ;i-=5){
        a5++;
    }


    for(long long i = n-n%25; i>n-m ; i-=25){
        a5++;
    }


    for(long long i = 5; i<=m ; i+=5){
        b5++;
    }



    for(long long i = 25; i<=m ; i+=25){
        b5++;
    }


    if(a5==0 || b5==0) cout << "0\n";
    else cout << a5-b5 << '\n';


}