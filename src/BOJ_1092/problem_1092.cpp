//배

#include<iostream>
#include<algorithm>

using namespace std;

int boxCheck[10001];

int main() {
    int n, m;
    cin >> n;

    int crain[n];
    for(int i=0; i<n; i++) {
        cin >> crain[i];
    }
    sort(crain, crain+n);


    cin >> m;

    int box[m];
    for(int i=0; i<m; i++) {
        cin >> box[i];
    }
    sort(box, box+m);

    

    int seconds = 0;
    while(1) {

        for(int i=m-1; i>=0; i--) {
            if(boxCheck[i]==0) {
                if(box[i]>crain[n-1]) {
                    cout << -1 << '\n';
                    return 0; 
                }  
            }
        }

        int index = m-1;
        for(int i=n-1; i>=0; i--) {
            if(boxCheck[index] == 0 && crain[i]>=box[index]) {
                boxCheck[index] = 1;
                index--;
            } else {
                index--;
                i++;
            }

            if(index<0) break;
        }

        seconds++;

        int cnt = 0;
        for(int i=m-1; i>=0; i--) {
            if(boxCheck[i]==1) {
                cnt++;
            }
        }
        if(cnt==m) break;
    }

    cout << seconds << '\n';
    

}