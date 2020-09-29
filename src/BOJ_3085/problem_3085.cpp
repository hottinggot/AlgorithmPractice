//사탕 게임

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    char c[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c[i][j];
        }
    }

    int cnt=1;
    int max=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(j+1<n){
                swap(c[i][j], c[i][j+1]);
                //가로 검사
                for(int k=0; k<n; k++){
                    for(int l=0;l<n;l++){
                        int right = l+1;
                        while(right<n && c[k][l]==c[k][right]){
                            cnt++;
                            right++;
                        }
                        if(max<cnt) max = cnt;
                        cnt=1;
                        l=right-1;
                    }
                }

                //세로 검사
                for(int k=0; k<n; k++){
                    for(int l=0;l<n;l++){
                        int down = l+1;
                        while(down<n && c[l][k]==c[down][k]){
                            cnt++;
                            down++;
                        }
                        if(max<cnt) max = cnt;
                        cnt=1;
                        l=down-1;
                    }
                }

                swap(c[i][j], c[i][j+1]);
            }

            if(i+1<n){
                swap(c[i][j], c[i+1][j]);
                //가로 검사
                for(int k=0; k<n; k++){
                    for(int l=0;l<n;l++){
                        int right = l+1;
                        while(right<n && c[k][l]==c[k][right]){
                            cnt++;
                            right++;
                        }
                        if(max<cnt) max = cnt;
                        cnt=1;
                        l=right-1;
                    }
                }

                //세로 검사
                for(int k=0; k<n; k++){
                    for(int l=0;l<n;l++){
                        int down = l+1;
                        while(down<n && c[l][k]==c[down][k]){
                            cnt++;
                            down++;
                        }
                        if(max<cnt) max = cnt;
                        cnt=1;
                        l=down-1;
                    }
                }
                swap(c[i][j], c[i+1][j]);
            }
            
        }
    }


    cout << max << '\n';
}