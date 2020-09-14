#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x;
    int p = 1;
    stack<int> s;
    string str;

    while(n--){
        cin >> x;
        if(x>=p){
            while(p<=x){
                s.push(p);
                str += '+';
                p++;
            }
            s.pop();
            str += '-';
        } else if(x<p && s.top()==x){
            s.pop();
            str += '-';
        } 
        
    }
    
    if(!s.empty()) cout << "NO" << '\n';
    else {
        for(char c : str){
            cout << c << '\n';
        } cout << '\n';
    }

}