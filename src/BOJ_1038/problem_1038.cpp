//감소하는 수

#include<iostream>

using namespace std;

int num[12];

int next(int n){

}

int main() {
    int index = 10;
    int jls = 11-index;

    int a;
    int b;

    int cnt = 0;

    for(int i=1; i<=jls; i++){
        if(jls>=2){
            b = num[index+1];
        } else {
            b = 0;
        }
        for(int j=b; j<=9; j++) {
            a = j;
            cnt++;
        }
        jls++;
        index--;
    }
    
 
}