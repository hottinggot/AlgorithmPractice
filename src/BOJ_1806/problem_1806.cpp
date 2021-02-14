//부분합

#include<iostream> 

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int *sp = arr;
    int *ep = arr;

    int sum = 0;
    int len = -1;

    while(1) {
        if(ep==arr+n+1) {
            break;
        }
        if(sum>=s) {
            if(len==-1 || len>ep-sp) len = ep-sp;
            sum-=*sp;
            sp++;
            
        } else {
            sum+=*ep;
            ep++;  
        }
    }

    if(len==-1) {
        cout << 0 << '\n';
    } else {
        cout << len << '\n';
    }

}