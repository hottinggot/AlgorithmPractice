#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    for(int i = 0; i < t;i++){
        string str;
        getline(cin, str);
        str += '\n';

        stack<char> s;

        for(char c : str){
            if(c == ' ' || c == '\n'){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << c;
            } else {
                s.push(c);
            }
        }
    }
    return 0;
}
