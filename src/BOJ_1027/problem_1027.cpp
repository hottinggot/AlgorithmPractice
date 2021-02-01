//고층 건물

#include<iostream>

using namespace std;

bool check[51][51];

int main() {
    int n;
    cin >> n;

    int b[n+1];
    for(int i=1; i<=n; i++) {
        cin >> b[i];
    }

    int maxi = 0;
    for(int i=1; i<=n; i++) {
        
        double arr[n+1];
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            arr[j] = (double)(b[i]-b[j])/(i-j);
        }
        
        int visible = 0;
        for(int index = 1; index<=n; index++) {
            if(index==i) continue;
            double a = arr[index];
            int cnt = 0;
            for(int k=1; k<=n; k++) {
                if(k==i) continue;
                if(index>i && k<index && k>i) {
                    if(a>arr[k]) cnt++;
                }
                else if(index<i && k<i && k>index) {
                    if(a<arr[k]) cnt++;
                }
            }
            if(i>index && cnt==i-index-1) visible++;
            else if(i<index && cnt==index-i-1) visible++;
        }

        if(visible>maxi) {
            maxi = visible;
        }
    }

    cout << maxi << '\n';
}