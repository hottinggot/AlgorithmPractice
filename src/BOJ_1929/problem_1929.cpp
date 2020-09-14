//소수구하기
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin >> m >> n;

    bool arr[n+1];
    for(int i=1; i<=n; i++){
        arr[i] = 0;
    }

    int j = 0;
    int k = 2;

    arr[0]=1;
    arr[1]=1;

    // 소수가 아니면 1, 소수이면 0.
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            j=i;
            while(j*k<=n){
                arr[j*k] = 1;
                k++;
            }
            k=2;
        }
    }

    for(int i=m; i<=n; i++){
        if(arr[i]==0) cout << i << '\n';
    }

}