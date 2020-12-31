//설탕 배달

#include<iostream>

using namespace std;


int main() {
    int n ;

    cin >> n;

    int cnt = 0;

    if(n%5==0){
        cout << n/5 << '\n';
        cnt++;
    } else {
        for(int i = n/5; i>=0; i--) {
            if((n-5*i)%3==0){
                cout << i+(n-5*i)/3 << '\n';
                cnt++;
                break;
            }
        }
    }

    if(cnt==0){
        cout << -1 << '\n';
    }

}