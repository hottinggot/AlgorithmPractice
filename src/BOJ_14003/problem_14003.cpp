//가장 긴 증가하는 부분 수열 5

#include<iostream>
#include<stack>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[n];
    int D[n+1];
    int p[n];

    D[0] = -1000000000;

    int index = 0;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        p[i] = -1;

        if(arr[i]>D[index]){
            D[++index] = arr[i];
            p[i] = index;
        } else {
            int l = 1;
            int r = index;
            int mid;
            int ans = 0;

            while (l<=r) {
                mid = (l+r)/2;
                if(D[mid]>=arr[i]) {
                    ans = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            D[ans] = arr[i];
            p[i] = ans;
        }
    }

    cout << index << '\n';

    stack<int> s;
    int t = index;
    
    for(int i = n-1; i>=0; i--) {
        
        if(p[i]==t) {
            s.push(arr[i]);
            t--;
        }

        if(t==0) break;
    }

    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}