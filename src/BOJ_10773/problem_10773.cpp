//제로

#include<iostream>
#include<stack>

using namespace std;

int main() {
    int k;
    cin >> k;

    stack<int> s;

    while(k--) {
        int n;
        cin >> n;
        if(n!=0) s.push(n);
        else s.pop();
    }

    int sum = 0;

    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    
    cout << sum <<'\n';
}