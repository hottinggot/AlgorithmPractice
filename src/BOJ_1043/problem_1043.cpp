//거짓말

#include<iostream>
#include<vector>

using namespace std;

int a[51];
vector<int> v[51];
int n, m;
int cnt = 0;
int maxi = 0;

void go(int num) {

    if(num>m) {
        if(cnt>maxi) maxi = cnt;
        return;
    }
  
    int t = 0;
    int f = 0;
    int b[n+1];
    for(int i=0; i<v[num].size(); i++) {
        b[v[num][i]] = a[v[num][i]];
        if(a[v[num][i]]==-1) f++;
        else if(a[v[num][i]]==1) t++;
    }

    if(t>0 && f>0) return;

    else if(t>0) {
        for(int i=0; i<v[num].size(); i++) {
            a[v[num][i]] = 1;
        }
        go(num+1);
        for(int i=0; i<v[num].size(); i++) {
            a[v[num][i]] = b[v[num][i]];
        }
    }

    else if(f>0) {
        cnt++;
        for(int i=0; i<v[num].size(); i++) {
            a[v[num][i]] = -1;
        }
        go(num+1);
        cnt--;
        for(int i=0; i<v[num].size(); i++) {
            a[v[num][i]] = b[v[num][i]];
        }
    }

    else {
        cnt++;
        for(int i=0; i<v[num].size(); i++) {
            a[v[num][i]] = -1;
        }
        go(num+1);
        cnt--;

        for(int i=0; i<v[num].size(); i++) {
            a[v[num][i]] = 1;
        }
        go(num+1);
        for(int i=0; i<v[num].size(); i++) {
            a[v[num][i]] = b[v[num][i]];
        }
    }
}


int main() {
    cin >> n >> m;

    int anum;
    cin >> anum;

    for(int i=0; i<anum; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    for(int i=1; i<=m; i++) {
        int x;
        cin >> x;
        for(int j=0; j<x; j++) {
            int person;
            cin >> person;
            v[i].push_back(person);
        }
    }

    go(1);
    cout << maxi << '\n';

}
