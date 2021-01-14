//LCS 2

#include<iostream>
#include<stack>

using namespace std;

int main() {
    string str1 = "0", str2 = "0";

    string in;
    
    cin >> in;
    str1 += in;

    cin >> in;
    str2 += in;

    int D[str1.length()][str2.length()];

    for(int i=0; i<str1.length();i++) {
        for(int j=0; j<str2.length();j++) {
            D[i][j] = 0;
        }
    }

    for(int i=0; i<str1.length();i++) {
        for(int j=0; j<str2.length();j++) {
            if(i==0 || j==0) {
                D[i][j] = 0;
                continue;
            }
            if(str1[i]==str2[j]) {
                D[i][j] = D[i-1][j-1]+1;
                
            } else {
                D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        }
    }

    cout << D[str1.length()-1][str2.length()-1] << '\n';

    int x = str1.length()-1;
    int y = str2.length()-1;

    stack<char> s;

    while(x>0 && y>0) {
        if(D[x-1][y]==D[x][y]) x = x-1;
        else if(D[x][y-1]==D[x][y]) y = y-1;
        else {
            s.push(str1[x]);
            x = x-1;
            y = y-1;
        }
    }
    
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

}