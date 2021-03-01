//좌표 압축

#include<iostream>
#include<queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<pair<int,int>> arr;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push({-x,i});
    }

    priority_queue<pair<int,int>> ans;
    int i=-1;
    int before = INT32_MIN;
    while(!arr.empty()) {
        if(-arr.top().first>before) i++;
        ans.push({-arr.top().second, i});
        before = -arr.top().first;
        arr.pop();
    }
   
    while (!ans.empty())
    {
        cout << ans.top().second << ' ';
        ans.pop();
    }
    
    cout << '\n';

}