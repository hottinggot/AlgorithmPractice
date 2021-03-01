//감소하는 수

#include<iostream>

using namespace std;

int D[1000000][10];

int main() {
    int n;
    cin >> n;

    for(int i=0; i<10; i++) {
        D[0][i] = 1;
    }

    int index=1;
    int k=1;
    bool flag = 0;
    while(1) {
        for(int i=1; i<10; i++) {
            for(int j=0; j<i; j++) {
                D[index][i] += D[index-1][j];
            }
            if(D[index][i]>=n) {
                flag = 1;
                break;
            }
            k = i;
        }
        if(flag==1) break;
        index++;
    }

    int beforeIdx;
    int beforeK = k;
    if(k==9) {
        beforeIdx = index-1;
    } else {
        beforeIdx = index;
    }

    for(int i = k*pow(10, beforeIdx); ;i++) {

    }

}