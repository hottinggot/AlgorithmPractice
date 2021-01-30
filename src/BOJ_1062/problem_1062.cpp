//가르침
//단어를 갯수만큼 배우지 않아도 되는 경우를 생각

#include<iostream>
#include<vector>

using namespace std;

int alpha[26];
int inclu[26];
int n, k;
int maxi = 0;
vector<string> v;
int total;

void go(int num, int index) {

    if(index>26) return;
    if(num>k) return;

    if(num==k || num==total) {
        int cnt = 0;
        for(int i=0; i<v.size(); i++) {
            int t=0;
            for(int j=0; j<v[i].length(); j++) {
                if(alpha[(int)(v[i][j]-'a')]==0) {
                    t++;
                    break;
                }
            }
            if(t==0) cnt++;
        }

        if(cnt>maxi) maxi = cnt;
        return;
    }

    if(inclu[index]==0) go(num, index+1);
    else if(index == 0 || index == (int)('n'-'a') || index == (int)('t'-'a') || index == (int)('i'-'a') || index == (int)('c'-'a')) 
        go(num, index+1);
    else {
        alpha[index] = 1;
        go(num+1, index+1);
        alpha[index] = 0;

        go(num, index+1);
    }
    
}

int main() {
    
    cin >> n >> k;

    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        v.push_back(s);

        for(int j=0; j<s.length(); j++) {
            inclu[(int)(s[j]-'a')] = 1;
        }
    }

    for(int i=0; i<26; i++) {
        if(inclu[i]==1) total++;
    }
    

    if(k<5) cout << 0 << '\n';
    else {
        alpha[0] = 1;
        alpha[(int)('n'-'a')] = 1;
        alpha[(int)('t'-'a')] = 1;
        alpha[(int)('i'-'a')] = 1;
        alpha[(int)('c'-'a')] = 1;

        go(5, 0);

        cout << maxi << '\n';
    }

}