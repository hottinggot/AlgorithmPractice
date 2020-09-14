#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(a%b==0) return b;
    else return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a,b;
    while(n--){
        cin >> a >> b;
        cout << a*b/gcd(a,b) << '\n';
    }
}