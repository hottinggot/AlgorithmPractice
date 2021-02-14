//크게 만들기

#include<iostream>
#include<stack>

using namespace std;

int arr[10];

int main() {
    int n,k;
    cin >> n >> k;
    
    string num;
    cin >> num;

    stack<char> s;

    int cnt = 0;
    for(int i=0; i<num.length(); i++) {
        if(cnt==k) {
            s.push(num[i]);
            continue;
        }

        if(s.empty()) {
            s.push(num[i]);
        } else {
            while(!s.empty() && cnt<k && s.top()<num[i]) {
                s.pop();
                cnt++;
            } 
            s.push(num[i]);
        }
    }

    if(cnt<k) {
        while(cnt!=k) {
            s.pop();
            cnt++;
        } 
    }

    stack<char> reverse;

    while(!s.empty()) {
        reverse.push(s.top());
        s.pop();
    }

    while(!reverse.empty()) {
        cout << reverse.top();
        reverse.pop();
    }
    cout << '\n';

    
    
}