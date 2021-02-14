//LCS 3

#include<iostream>

using namespace std;

int main() {
    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    s1.insert(s1.begin(), ' ');
    s2.insert(s2.begin(), ' ');
    s3.insert(s3.begin(), ' ');

    int arr[s1.length()][s2.length()][s3.length()];

    int maxi = 0;

    for(int i=0; i<s1.length(); i++) {
        for(int j=0; j<s2.length(); j++) {
            for(int k=0; k<s3.length(); k++) {
                if(i==0 || j==0 || k==0) {
                    arr[i][j][k] = 0;
                    continue;
                }

                if(s1[i]==s2[j] && s2[j]==s3[k]) {
                    arr[i][j][k] = arr[i-1][j-1][k-1]+1;
                    
                }
                else {
                    arr[i][j][k] = max(max(arr[i-1][j][k], arr[i][j-1][k]), arr[i][j][k-1]);
                }

                if(arr[i][j][k]>maxi) maxi = arr[i][j][k];
            }
        }
    }

    cout << maxi << '\n';
}