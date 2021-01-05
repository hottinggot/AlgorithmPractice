//LCS

#include<iostream>

using namespace std;

int cnt[1001][1001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int maxi = -1;

    for(int j=0; j<=s2.length(); j++) {
        for(int i=0; i<=s1.length(); i++) {
            if (j==0 || i==0) cnt[j][i] = 0;

            else if (s1[i-1] == s2[j-1])
                    cnt[j][i] = cnt[j-1][i-1] + 1;
             
            else {
                int temp = cnt[j][i-1];
                if(cnt[j-1][i] > temp) temp = cnt[j-1][i];
                cnt[j][i] = temp;
            }
            
        }
    }

    cout << cnt[s2.length()][s1.length()] << '\n';
    

}