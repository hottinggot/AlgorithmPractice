//N과 M (2)

#include<iostream>

using namespace std;

int arr[10];

void go(int n, int m, int index, int start){

    if(index==m) {
        for(int i=0; i<m-1; i++) {
            cout << arr[i] << ' ';
        }
        cout << arr[m-1] << '\n';
        return;
    }

    if(start>n) {
        return;
    }
    
    
        
    arr[index] = start;
    go(n, m, index+1, start+1);
    
    go(n, m, index, start+1);
        
    

}

int main(){
    int n, m;
    cin >> n >> m;

    go(n,m,0,1);

}