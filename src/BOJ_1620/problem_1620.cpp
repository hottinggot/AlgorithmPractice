//나는야 포켓몬 마스터 이다솜

#include<iostream>
#include<map>
#include<cctype>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin >> n >> m;

    map<string, int> mmap;
    string arr[n+1];

    for(int i=1; i<=n; i++) {
        string str;
        cin >> str;
        mmap.insert({str,i});
        arr[i] = str;
    }

    map<string, int>::iterator iter;

    for(int i=0; i<m; i++) {
        string s;
        cin >> s;

        int temp;
        temp = atoi(s.c_str());
        if(temp>0 && temp<=n) {
            cout << arr[temp] << '\n';
        } else {
            cout << mmap[s] << '\n';
        }
    }
}