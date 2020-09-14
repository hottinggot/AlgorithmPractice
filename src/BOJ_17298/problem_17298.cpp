#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> ans(n);

    for(int i=0; i<n;i++){
        cin >> a[i];
        ans[i] = -1;
    }

    stack<int> s;

    for(int i=0; i<n; i++){
        while(!s.empty() && a[i]>a[s.top()]){
            ans[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i=0; i<n;i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

}