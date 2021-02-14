//단어 수학
//https://ideone.com/Tl6klp

#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int b[26];
int c[26];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.length() ;j++) {
            b[s[j]-'A'] += pow(10, s.length()-j-1);
        }
    }

    sort(b, b+26);

    int sum = 0;
    int num = 9;

    for(int i=25; i>=0; i--) {
        if(b[i]==0) break;
        sum+=b[i]*num;
        num--;
    }

    cout << sum << '\n';

}