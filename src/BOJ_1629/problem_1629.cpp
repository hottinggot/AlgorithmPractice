//곱셈

#include<iostream>

using namespace std;

long long mul(long long a, long long b, long long c){
    if(b==0) {
        return 1;
    } else {
        long long temp = mul(a, b/2, c);
        temp = temp*temp%c;
        if(b%2 == 0) {
            return temp;
        }
        else {
            temp = temp*a%c;
            return temp;
        }
    }
}
 
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b,c;
    cin >> a >> b >> c;

    cout << mul(a,b,c) << '\n';
}