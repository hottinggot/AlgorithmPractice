//신입 사원

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<pair<int, int>> grade;

        for(int i=0; i<n; i++) {
            int s,m;
            cin >> s >> m;
            grade.push_back({s,m});
        }

        sort(grade.begin(), grade.end());

        int cnt = 1;
    
        int min = grade[0].second;

        for(int i=1; i<n; i++) {
            if(grade[i].second<min){
                cnt ++;
                min = grade[i].second;
            }
        }

        cout << cnt << '\n';

    }
}