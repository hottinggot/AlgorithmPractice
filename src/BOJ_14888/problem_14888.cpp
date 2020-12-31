//연산자 끼워넣기

#include<iostream>

using namespace std;

int a[12];
int op[4];
int maxi = -1000000000;
int mini = 1000000000;

int cal(int op, int a, int b){
    switch (op)
    {
        case 0:
            return a+b;
        
        case 1:
            return a-b;
        
        case 2:
            return a*b;

        case 3:
            return a/b;

        default: return 0;     
    }
}

void dfs(int anum, int n, int index){

    if(index > n) return;
    if(index == n) {
        if(anum > maxi) maxi = anum;
        if(anum < mini) mini = anum;
    }

    int temp;
    for(int i=0; i<4; i++) {
        if(op[i]>0){
            temp = cal(i, anum, a[index+1]);
            op[i]--;
            dfs(temp, n, index+1);
            op[i]++;
        }
    }
}

int main() {
    int n;
    cin >> n;  

    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<4; i++){
        cin >> op[i];
    }

    dfs(a[1], n, 1);

    cout << maxi << '\n';
    cout << mini << '\n';

}