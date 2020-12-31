//스도쿠

#include<iostream>
#include<vector>

using namespace std;

int sdk[9][9];
vector<pair<int, int>> v;
bool p;

int promising(int x, int y, int n) {
    for(int i=0; i<9; i++) {
        if(sdk[x][i]==n) return 0;
        if(sdk[i][y]==n) return 0;
    }

    for(int i = (x/3)*3; i<(x/3)*3+3; i++){
        for(int j = (y/3)*3; j<(y/3)*3+3; j++){
            if(sdk[i][j]==n) return 0;
        }
    }

    return 1;
}

void go(int cnt) {

    if(cnt == v.size() && !p) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sdk[i][j] << ' ';
            }
            cout << '\n';
        }
        p = true;
        return;
    }

    for(int i=1; i<=9; i++) {
        if(promising(v[cnt].first, v[cnt].second, i)==1){
            sdk[v[cnt].first][v[cnt].second] = i;
            go(cnt+1);
            sdk[v[cnt].first][v[cnt].second] = 0;
        }
    }
}


int main()
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) {
            int n;
            cin >> n;

            sdk[i][j] = n;

            if(n==0) v.push_back({i,j});
        }
    }

    go(0);

}