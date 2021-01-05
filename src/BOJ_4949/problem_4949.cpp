//균형잡힌 세상

#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int main() {
    while(1) {
        string str;

        getline(cin, str);

        if(str.compare(".")==0) return 0;

        stack<char> s;

        int yes = 1;

        for(int i=0; i<str.length() ; i++) {
            if(str[i]=='(' || str[i]=='[')
                s.push(str[i]);
            else if(str[i]==')'){
                if(!s.empty() && s.top() == '(') s.pop();
                else {
                    yes = 0;
                    break;
                }
            } else if(str[i]==']'){
                if(!s.empty() && s.top()=='[') s.pop();
                else {
                    yes = 0;
                    break;
                }
            }
        }

        if(!s.empty()) {
            yes = 0;
        }

        if(yes == 1) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
}