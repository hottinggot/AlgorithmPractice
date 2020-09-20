//연속합

#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[n];
    int s[n];
    int max[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
        max[i]=0;
        if(i==0) s[i] = a[i];
        else {
            if(s[i-1]+a[i]>a[i]) s[i] = s[i-1]+a[i];
            else{
                s[i] = a[i];
            }

        }
        
    }

    int m=s[0];
    for(int i=0; i<n; i++){
        
        if(s[i]>m) m = s[i];
    }

    cout << m <<'\n';
}