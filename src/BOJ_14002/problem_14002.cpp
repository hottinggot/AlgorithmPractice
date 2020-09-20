//가장 긴 증가하는 부분 수열 4

#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[n];
    int v[n];
    int p[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
        v[i]=1;
        p[i] = -1;

        for(int j=i-1;j>=0;j--){
            if(a[i]>a[j] && v[j]>v[i]-1){
                v[i]=v[j]+1;
                p[i]=j;
            }
        }
    }

    int max=0;
    int index=0;

    for(int i=0; i<n; i++){
        if(v[i]>max) {
            max=v[i];
            index=i;
        }
    }

    stack<int> s;
    s.push(a[index]);

    while(p[index]!=-1){
        index = p[index];
        s.push(a[index]);
    }

    cout << max << '\n';

    while(!s.empty()){
        if(s.size()==1) cout << s.top() << '\n';
        else cout << s.top() << ' ';
        s.pop();
    }
}