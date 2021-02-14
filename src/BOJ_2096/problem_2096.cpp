//내려가기

#include<iostream>

using namespace std;

int maxD[2][3];
int minD[2][3];
int arr[100001][3];

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }

    maxD[0][0] = arr[1][0];
    maxD[0][1] = arr[1][1];
    maxD[0][2] = arr[1][2];

    minD[0][0] = arr[1][0];
    minD[0][1] = arr[1][1];
    minD[0][2] = arr[1][2];

    for(int i=2; i<=n; i++) {
        maxD[1][0] = max(maxD[0][0], maxD[0][1]) + arr[i][0];
        maxD[1][1] = max(max(maxD[0][0], maxD[0][1]), maxD[0][2]) + arr[i][1];
        maxD[1][2] = max(maxD[0][1], maxD[0][2]) + arr[i][2];

        minD[1][0] = min(minD[0][0], minD[0][1]) + arr[i][0];
        minD[1][1] = min(min(minD[0][0], minD[0][1]), minD[0][2]) + arr[i][1];
        minD[1][2] = min(minD[0][1], minD[0][2]) + arr[i][2];

        maxD[0][0] = maxD[1][0];
        maxD[0][1] = maxD[1][1];
        maxD[0][2] = maxD[1][2];

        minD[0][0] = minD[1][0];
        minD[0][1] = minD[1][1];
        minD[0][2] = minD[1][2];
        
    }

    cout << max(max(maxD[0][0], maxD[0][1]), maxD[0][2]) << ' ' << min(min(minD[0][0], minD[0][1]), minD[0][2]) <<'\n';
}