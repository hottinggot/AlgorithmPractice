//친구 네트워크

#include<iostream>
#include<map>

using namespace std;

map<string, pair<string,int>> m;

string find (string s) {
    if(m[s].first==s) {
        return s;
    } else {
        string temp = find(m[s].first);
        m[s].second = m[temp].second;
        return m[s].first = temp;
    }
}

int Union(string s1, string s2) {
    s1 = find(s1);
    s2 = find(s2);

    if(s1!=s2) {
        m[s2] = {s1, m[s1].second + m[s2].second};
        m[s1].second = m[s2].second;
    }

    return m[s2].second;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {

        m.clear();

        int f;
        cin >> f;

        for(int i=0; i<f; i++) {
            string s1,s2;
            cin >> s1 >> s2;

            if(m.find(s1)==m.end()) {
                m.insert({s1, {s1,1}});
            }
            if(m.find(s2)==m.end()) {
                m.insert({s2, {s2,1}});
            }

            cout << Union(s1, s2) << '\n';
        }
    }
}