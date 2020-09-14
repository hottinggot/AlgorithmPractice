#include<iostream>

using namespace std;

bool arr[1000001];

void eratos(){
    for(int i=0; i<=1000000; i++){
        arr[i] = 0;
    }

    arr[0]=1;
    arr[1]=1;

    int j=0;
    int k=2;

    for(int i = 2; i<=1000000; i++){
        if(arr[i]==0) {
            j=i;
            while(j*k<=1000000){
                arr[j*k] = 1;
                k++;
            }
            k=2;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a=0, b=0;
    eratos();

    while(1)
    {
        cin >> n;
        if(n==0) break;
        for(int i = 3; i<=n/2; i++){
            if(arr[i]==0 && arr[n-i]==0){
                a = i;
                b = n-i;
                break;
            }
        }
        if(a==0 || b==0){
            cout << "Goldbach's conjecture is wrong.\n"; 
        }
        else{
            cout << n << " = " << a << " + " << b << '\n';
        }

    }

}