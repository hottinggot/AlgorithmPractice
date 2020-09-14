#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    stack<char> s;
    queue<char> q;

    string ans;

    int i = 0;

    while(i<str.length()){
        if(str[i] == '<'){
            while(str[i]!='>'){
                ans += str[i++];
            }
            ans += str[i++];
        }
        
        if(str[i] != ' ' && str[i]!='<' && i<str.length()){
            while(str[i]!=' ' && i<str.length() && str[i]!='<'){
                s.push(str[i++]);
            }
            while(!s.empty()){
                ans += s.top();
                s.pop();
            }
            if(str[i] == ' ') ans += str[i++];
        }
    }

    cout << ans << '\n';
}