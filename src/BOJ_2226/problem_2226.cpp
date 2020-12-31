//이진수

#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

struct node{
    bool num = 0;
    bool left = 0;
    bool right = 0;
};

node setNode(node n) {
    if(n.num==1){
        n.left = 0;
        n.right = 1;
    }
    else if(n.num==0){
        n.left = 1;
        n.right = 0;
    }
    return n;
}

int main() {

    int n;
    cin >> n;

    node nd;

    long long x = (1<<(n-1));
    node arr1[x];
    node arr2[x];

    arr1[0].num = 1;
    arr1[0] = setNode(arr1[0]);
 

    for(int i=0; i<n-1; i++) {

        for(int j=0; j<(1<<i); j++){
            arr2[j*2].num = arr1[j].left;
            arr2[j*2] = setNode(arr2[j*2]);
            arr2[j*2+1].num = arr1[j].right;
            arr2[j*2+1] = setNode(arr2[j*2+1]);
        }

        for(int j=0; j<(1<<i)*2; j++) {
            arr1[j] = arr2[j];
        }
    }
    

    int cnt = 0;

    for(int i=0; i<x; i++) {
        int zero=0;
        while(arr1[i].num==0){
            zero++;
            i++;
        }
        if(zero>0) cnt++;
    }

    cout << cnt << '\n';

}

