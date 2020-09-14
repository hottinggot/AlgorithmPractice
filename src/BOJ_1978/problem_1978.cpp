#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    int num;
    int cnt = 0;
    int b=0;
    while(n--){
        cin >> num;
        if(num<2) ;
        else if(num==2) cnt++;
        else{
            for(int i=2;i*i<=num; i++){
                if(num%i == 0) b++;
            }
            if(b==0) cnt++;
            b=0;
        }
    }
    cout << cnt << '\n';
}