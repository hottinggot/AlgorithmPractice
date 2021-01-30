//감소하는 수

#include<iostream>

using namespace std;

int cnt = 0;
int temp = 0;
int jls = 1;


void dfs(int k) {
    if(k==0) {
        cnt++;

        //k생성
    }

    int t = k%10;
    if(t<(t/10)%10) {
        dfs(k/10);
    }

}

int main() {
    int n;
    cin >> n;

    dfs(0);
}