//리모컨

#include<iostream>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    cin >> s;

    int m;
    cin >> m;

    bool x[10];

    for(int i=0; i<10; i++){
        x[i] = true;
    }
    
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        x[a] = false;
    }


    bool channel[1000000];

    for(int i=0; i<1000000; i++){
        channel[i] = true;
    }

    for(int i=0; i<1000000; i++){
        int c=i;
        while(1){
            if(!x[c%10]) {
                channel[i] = false;
                break;
            }
            c=c/10;
            if(c==0) break;
        }
    }

    int cnt = 0;

    if(s>=100){
        if(cnt==0 || s-100<cnt) cnt=s-100;
    } else if(s<100){
        if(cnt==0 || 100-s<cnt) cnt=100-s;
    }
    for(int i=0; i<1000000; i++) {
        if(channel[i]){

            int zls=0;
            int k=i;

            while(1) {
                if(k==0) break;
                k=k/10;
                zls++;
            }

            if(i==0) zls=1;

            if(i==s) {
                if(zls<cnt) cnt=zls;
                break;
            }

            if(i>s) {
                if(i-s+zls<cnt) cnt=i-s+zls;
            }
            if(i<s) {
                if(s-i+zls<cnt) cnt=s-i+zls;
            }
            
        }
    }

    cout << cnt << '\n';
    

}