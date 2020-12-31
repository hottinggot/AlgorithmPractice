//회의실배정

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> time;

    for(int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;

        time.push_back({y,x});
    }

    sort(time.begin(), time.end());

    int cnt = 0;
    int finishTime = 0;
    int x = -1;
    int idx = -1;

    while(1) {
        for(int i=idx+1; i<n; i++) {
            if(time[i].second >= finishTime ){
                finishTime = time[i].first;
                x = i;
                idx = i;
                break;
            }
        }

        if(x==-1) break;

        x = -1;
        cnt ++;
    }

    cout << cnt << '\n';
    
}