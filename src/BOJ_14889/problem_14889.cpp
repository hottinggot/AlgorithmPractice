//스타트와 링크

#include<iostream>
#include<vector>
#include <climits>

using namespace std;

int S[21][21];
int check[21];

int diff = INT_MAX;

vector<int> startChose;
vector<int> linkChose;

void dfs(int n, int index) {

    if(index > n) {
        
        if(startChose.size() == n/2 && linkChose.size() == n/2) {

            int start = 0;
            int link = 0;

            for(int i=0; i<n/2; i++) {
                for(int j=i+1; j<n/2; j++){
                    start += (S[startChose[i]][startChose[j]] + S[startChose[j]][startChose[i]]);
                    link += (S[linkChose[i]][linkChose[j]] + S[linkChose[j]][linkChose[i]]);
                }
            }

            if(abs(start - link) < diff) diff = abs(start-link);
        }
        return;
    }

    startChose.push_back(index);
    dfs(n, index+1);
    startChose.pop_back();

    linkChose.push_back(index);
    dfs(n, index+1);
    linkChose.pop_back();

}

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> S[i][j];
        }
    }

    vector<pair<int, int>> v;

    dfs(n, 1);

    cout << diff << '\n';

}