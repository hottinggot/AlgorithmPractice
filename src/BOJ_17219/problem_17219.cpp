// /비밀번호 찾기

#include<iostream>
#include<map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n,m;
    cin >> n >> m;

    map<string, string> mmap;
    for(int i=0; i<n; i++) {
        string site;
        string passwd;
        cin >> site >> passwd;

        mmap[site] = passwd;
    }

    for(int i=0; i<m ; i++) {
        string site;
        cin >> site;
        cout << mmap.find(site)->second << '\n';
    }

}