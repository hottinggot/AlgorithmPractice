//램프

#include<iostream>

using namespace std;

int n,m;
int k;
int arr[51][51];

int main() {
    
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1d",&arr[i][j]);
        }
    }
    cin >> k;

    int maxi = 0;
    for(int i=1; i<=n; i++) {
        int zerocnt = 0;
        for(int j=1; j<=m; j++) {
            if(arr[i][j]==0) zerocnt++;
        }

        if(k>=zerocnt && (k-zerocnt)%2==0) {
            int row = 0;
            for(int l=1; l<=n; l++) {
                int temp = 0;
                for(int p=1; p<=m; p++) {
                    if(arr[l][p]!=arr[i][p]) {
                        temp++;
                        break;
                    }
                }
                if(temp==0) row++;
            }
            if(row > maxi) maxi = row;
        }
    }

    cout << maxi << '\n';

}