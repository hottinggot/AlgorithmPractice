//패션왕 신해빈

#include<iostream>
#include<map>

using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> mmap;
        
        for(int i=0; i<n; i++) {
            string str;
            string kind;

            cin >> str >> kind;
            mmap[kind]++;
        }

        int cnt = 1;
        map<string, int>::iterator iter;
        for(iter = mmap.begin(); iter!=mmap.end(); iter++) {
            cnt*=((iter->second)+1);
        }
        cout << cnt-1 << '\n';
    }
}