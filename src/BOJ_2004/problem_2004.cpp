//조합 0의 개수

#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m ;

    if(n/2<m) m=n-m;

    int a2=0,a5=0;
    int b2=0,b5=0;
    int temp;

    for(int i = n;i > n-m; i--){
        temp = i;
        while(temp%2==0){
            a2++;
            temp = temp/2;
        }

        while(temp%5==0){
            a5++;
            temp = temp/5;
        }
    }

    for(int i = 1; i<=m; i++){
        temp = i;
        while(temp%2==0){
            b2++;
            temp = temp/2;
        }
        while(temp%5==0){
            b5++;
            temp = temp/5;
        }
    }

    if(a2-b2<=0 || a5-b5<=0) cout << "0\n";
    else if(a2-b2>a5-b5){
        cout << a5-b5 << '\n';
    }
    else cout << a2-b2 << '\n';

}