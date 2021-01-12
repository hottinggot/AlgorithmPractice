//바이러스

#include<iostream>
#include<vector>

using namespace std;

vector<int> list[101];
bool check[101];
int cnt;

void dfs(int n) {

    check[n] = 1;
    cnt++;

    for(int i=0; i<list[n].size(); i++) {
        if(check[list[n][i]]==0) dfs(list[n][i]);
    }

}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i=0; i<k; i++) {
        int x,y;
        cin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    dfs(1);

    cout << cnt-1 << '\n';


}