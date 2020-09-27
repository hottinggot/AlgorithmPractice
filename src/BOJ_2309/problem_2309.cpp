//일곱 난쟁이

#include<iostream>

using namespace std;

void sort(int* arr, int n){

    int temp;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n[9];
    int sum = 0;
    for(int i=0; i<9; i++){
        cin >> n[i]; 
        sum += n[i];
    }

    int tempi;
    int tempj;

    for(int i=0; i<9; i++){
        int sum2 = sum-n[i];
        for(int j=0; j<9 && j!=i;j++){
            if(sum2-n[j] ==100) {
                tempi = n[i];
                tempj = n[j];
            }
        }
    }

    sort(n, 9);

    for(int i=0; i<9; i++){
        if(n[i]!=tempi && n[i]!=tempj)
            cout << n[i] << '\n';
    }
}