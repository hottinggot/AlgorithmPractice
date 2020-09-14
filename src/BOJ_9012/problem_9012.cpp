#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i = 0; i<t; i++){
        string str;
        cin >> str;

        stack<char> s;

        for(char c : str){
            if(c == '('){
                s.push(c);
            } else {
                if(!s.empty()) s.pop();
                else {
                    s.push(c);
                    break;
                }
            }
        }

        if(s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

}