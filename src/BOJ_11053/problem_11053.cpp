//가장 긴 증가하는 부분 수열

#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[n];
    int v[n];
    int max=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        v[i]=1;

        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]) {
                if(v[j]>v[i]-1) v[i]=1+v[j];
            }
        }
        if(v[i]>max) max=v[i];
    }

    cout << max <<'\n';

}