//체스

#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> v;

bool finished = 0;

void cal(int x, int y, int endX, int endY, int cnt) {

    if(cnt>4 || finished==1) return;

    if(x == endX && y == endY) {
        finished = 1;
        cout << cnt << ' ';

        for(int i=0; i<v.size(); i++) {
            cout << (char)(v[i].first) << ' ' << v[i].second << ' ';
        }
        return;
    }
    
    for(int i=1; (x+i<(int)('A'+8) && y+i<=8) ; i++) {
        v.push_back({x+i, y+i});
        cnt++;
        cal(x+i, y+i, endX, endY, cnt);
        cnt--;
        v.pop_back();
    }

    for(int i=1; (x-i>=(int)'A' && y-i>=1) ; i++) {
        v.push_back({x-i, y-i});
        cnt++;
        cal(x-i, y-i, endX, endY, cnt);
        cnt--;
        v.pop_back();
    }

    for(int i=1; (x-i>=(int)'A' && y+i<=8) ; i++) {
        v.push_back({x-i, y+i});
        cnt++;
        cal(x-i, y+i, endX, endY, cnt);
        cnt--;
        v.pop_back();
    }

    for(int i=1; (x+i<(int)('A'+8) && y-i>=1) ; i++) {
        v.push_back({x+i, y-i});
        cnt++;
        cal(x+i, y-i, endX, endY, cnt);
        cnt--;
        v.pop_back();
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        char startX, endX;
        int startY, endY;

        finished = 0;
        v.clear();

        cin >> startX >> startY >> endX >> endY;

        if((abs((int)endX-(int)startX) + abs(endY-startY))%2 == 1) {
            cout << "Impossible\n";
        } else {
            v.push_back({(int)startX, startY});
            cal((int)startX, startY, (int)endX, endY, 0);
        }
    }
}