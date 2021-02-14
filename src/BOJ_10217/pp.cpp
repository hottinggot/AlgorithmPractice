#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
struct path {
    int v;
    int c;
    int t;
};

int table[100][10001];

int dp(int n, int v, int m, vector<path> graph[]) {
    if (m < 0) return -1;
    if (v == n - 1) return 0;
    if (table[v][m] != 0) return table[v][m];

    int min_time = INT32_MAX;
    for (int i = 0; i < graph[v].size(); ++i) {
        path p = graph[v][i];
        int tt = dp(n, p.v, m - p.c, graph);

        if (tt == -1) continue;
        tt += p.t;
        if (tt < min_time) min_time = tt;
    }

    int r = min_time == INT32_MAX ? -1 : min_time;
    table[v][m] = r;
    return r;
}

void ttt() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<path> graph[n];
    memset(table, 0, sizeof(int) * 100 * 10001);

    for (int i = 0; i < k; ++i) {
        int u;
        path p;
        cin >> u >> p.v >> p.c >> p.t;
        p.v--;
        graph[u - 1].push_back(p);
    }

    int r = dp(n, 0, m, graph);
    if (r == -1)
        cout << "Poor KCM\n";
    else
        cout << r << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ttt();
    }
    return 0;
}