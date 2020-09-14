#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int temp;
    int cnt2 = 0, cnt5=0;

    for(int i = 1; i<=n; i++){
        temp = i;
        while(temp%2==0){
            cnt2++;
            temp = temp/2;
        }

        while(temp%5==0){
            cnt5++;
            temp = temp/5;
        }
    }

    if(cnt2==0 || cnt5==0) cout << "0\n";
    else if(cnt2>cnt5){
        cout << cnt5 << '\n';
    } else cout << cnt2 << '\n';
}