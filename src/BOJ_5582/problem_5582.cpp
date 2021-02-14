//공통 부분 문자열

#include<iostream>
#include<memory.h>

using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    s1.insert(s1.begin(), '0');
    s2.insert(s2.begin(), '0');

    int arr[s1.length()][s2.length()];

    memset(arr, 0, sizeof(arr));

    int maxi = 0;

    for(int i=0; i<s1.length(); i++) {
        for(int j=0; j<s2.length(); j++) {
            if(i==0 || j==0)  {
                arr[i][j] = 0;
                continue;
            }
            if(s1[i]==s2[j]) {
                arr[i][j] = arr[i-1][j-1]+1;
                if(arr[i][j]>maxi) maxi = arr[i][j];
            }
        }
    }

    cout << maxi << '\n';

}