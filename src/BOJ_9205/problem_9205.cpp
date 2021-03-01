//맥주 마시면서 걸어가기
#include<iostream>
#include<vector>

using namespace std;

int INF = 987654321;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int num = 20;


        vector<pair<int,int>> list;
        int arr[102][102];
        for(int i=0; i<n+2; i++) {
            int x,y;
            cin >> x >> y;

            list.push_back({x,y}); 
        }

        for(int i=0; i<n+2; i++) {
            for(int j=0; j<n+2; j++) {
                if(i==j) {
                    arr[i][j] = 0;
                    continue;
                }
                arr[i][j] = abs(list[i].first-list[j].first) + abs(list[i].second-list[j].second);
                if(arr[i][j]>1000) arr[i][j] = INF;
            }
        }

        for(int k=0; k<n+2; k++) {
            for(int i=0; i<n+2; i++) {
                for(int j=0; j<n+2; j++) {
                    if(arr[i][k]!=INF && arr[k][j]!=INF) {
                        if(arr[i][k]+arr[k][j]<arr[i][j]) {
                            arr[i][j] = arr[i][k]+arr[k][j];
                        }
                    }
                }
            }
        }

        if(arr[0][n+1]!=INF) cout<<"happy\n";
        else cout << "sad\n";
    }
}