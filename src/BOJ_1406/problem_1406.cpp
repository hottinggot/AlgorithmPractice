#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int m;
    cin >> m;

    stack<char> a;
    stack<char> b;

    for(char x: str){
        a.push(x);
    }

    char cmd;
    while(m--){
        cin >> cmd;
        if(cmd == 'P'){
            char ch;
            cin >> ch;
            a.push(ch);
        }
        else if(cmd == 'B'){
            if(!a.empty())
                a.pop();
        }
        else if(cmd == 'D'){
            if(!b.empty()){
                a.push(b.top());
                b.pop();
            }
        }
        else if(cmd == 'L'){
            if(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
    }

    stack<char> inverse;
    string ans;
    while(!a.empty()){
        inverse.push(a.top());
        a.pop();
    }

    while(!inverse.empty()){
        ans += inverse.top();
        inverse.pop();
    }

    while(!b.empty()){
        ans += b.top();
        b.pop();
    }

    cout << ans << '\n';

}