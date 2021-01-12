//최소비용 구하기 2

#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

vector<pair<int, int>> list[1001];
int check[1001];
int p[1001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        list[start].push_back({end, cost});
    }

    for(int i=0; i<1001; i++) {
        check[i] = -1;
    }

    int from, to;
    cin >> from >> to;

    queue<pair<int, int>> q;
    
    q.push({from, 0});
    check[from] = 0;
    p[from] = from;

    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        for(int i=0; i<list[f.first].size(); i++){
            int x = list[f.first][i].first;
            int w = list[f.first][i].second;

            if(check[x] == -1 || check[x]>check[f.first]+w) {
                q.push(list[f.first][i]);
                check[x] = check[f.first] + w;
                p[x] = f.first;
            }
        }
    }

    cout << check[to] << '\n';

    stack<int> s;
    int index = to;
    int cnt = 1;

    while(index!=from) {
        s.push(index);
        index = p[index];
        cnt++;
    }
    s.push(from);

    cout << cnt << '\n';

    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

}