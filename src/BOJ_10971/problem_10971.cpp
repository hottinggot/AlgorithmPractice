//외판원 순회 2

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int w[n][n];

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }

    vector<int> v;

    for (int i=1; i<=n; i++) {
        v.push_back(i);
    }

    int min=-1;

    do{
        int sum = 0;

        if(w[v[n-1]-1][v[0]-1]!=0){
            sum += w[v[n-1]-1][v[0]-1];
        
            for(int i=0; i<n-1; i++) {
                if(w[v[i]-1][v[i+1]-1]==0) {
                    sum=0;
                    break;
                }
                sum += w[v[i]-1][v[i+1]-1];
            }
        }
        

        if(sum>0)
            if(min==-1 || min>sum) min=sum;

    } while(next_permutation(v.begin()+1, v.end()));

    cout << min << '\n';
}