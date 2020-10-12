//N과 M (1)

#include<iostream>

using namespace std;
int arr[9];
bool c[9];

void go(int index, int n, int m){

    if(index==m){
        for(int i=0 ; i<m-1; i++) {
            cout << arr[i] << ' ';
        }
        cout << arr[m-1] << '\n';
        return;
    }


    for(int i=1; i<=n; i++){
        if(!c[i]){
            arr[index] = i;
            c[i] = true;
            go(index+1, n, m);
            c[i] = false;
        }
    }

    
    

}

int main(){
    int n, m;
    cin >> n >> m;

    go(0, n, m);
}