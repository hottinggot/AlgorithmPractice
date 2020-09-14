#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int n = 0;
    int total = 0;
    int l = 0;
    stack<char> s;

    for(char c: str){
        if(c=='('){
            s.push(c);
            n++;
        }
        else if(c==')' && s.top()=='('){
            s.push(c);
            n--;
            l = l+2;
            total += n;
        } else {
            s.push(c);
            total++;
            l=0;
            n--;
        }
    }

    cout << total << '\n';

}