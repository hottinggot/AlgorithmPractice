//카드 게임

#include<iostream>
#include<memory.h>

using namespace std;

int arr[1001];
int D[1001][1001];

int cal(int start, int end, int maxVal) {
    if(D[start][end] >= 0) return D[start][end];

    if(start>end) return 0;

    if(maxVal==1) {
        D[start][end] = max(arr[start] + cal(start+1, end, 0), arr[end] + cal(start, end-1, 0));
    } else {
        D[start][end] = min(cal(start+1, end, 1), cal(start, end-1, 1));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    }

    return D[start][end];

}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        memset(D, -1, sizeof(D));

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << cal(0, n-1, 1) << '\n';
    }
}