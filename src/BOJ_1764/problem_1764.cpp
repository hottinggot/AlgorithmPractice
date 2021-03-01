//듣보잡

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    map<string,int> mmap;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        mmap[str] = 1;
    }

    vector<string> ans;
    for(int i=0; i<m; i++) {
        string str;
        cin >> str;
        map<string,int>::iterator iter;
        if(mmap.find(str)!=mmap.end()) {
            ans.push_back(str);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}