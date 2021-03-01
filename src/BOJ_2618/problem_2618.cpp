//경찰차
#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

int D[1002][1002];
pair<int,int> arr[1002];

int go(int a, int b, int w) {
    int cur = max(a,b);
    if(cur==w) return 0;

    if(D[a][b]!=-1) return D[a][b];
    int t1 = go(cur+1,b,w) + abs(arr[cur+1].first-arr[a].first) + abs(arr[cur+1].second-arr[a].second);
    int t2 = go(a, cur+1,w) + abs(arr[cur+1].first-arr[b].first) + abs(arr[cur+1].second-arr[b].second);
    D[a][b] = min(t1,t2);

    return D[a][b];
}

void print(int a, int b, int w) {
    int cur = max(a,b);
    if(cur==w) return;
    
    int t1 = go(cur+1,b,w) + abs(arr[cur+1].first-arr[a].first) + abs(arr[cur+1].second-arr[a].second);
    int t2 = go(a, cur+1,w) + abs(arr[cur+1].first-arr[b].first) + abs(arr[cur+1].second-arr[b].second);
    if(t1>t2) {
        cout << 2 << '\n';
        print(a,cur+1,w);
    }

    else {
        cout << 1 << '\n';
        print(cur+1, b,w);
    }
}

int main() {
    int n;
    int w;
    cin >> n;
    cin >> w;

    memset(D, -1, sizeof(D));
    arr[0] = {1,1};
    arr[1] = {n,n};

    for(int i=2; i<=w+1; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << go(0,1,w+1) << '\n';

    print(0,1,w+1);
}