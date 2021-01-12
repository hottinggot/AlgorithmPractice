//DSLR

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int p[10001];
char c[10001];

int main() {
    int t;
    cin >> t;
    while(t--) {

        for(int i=0; i<10001; i++) {
            p[i] = -1;
            c[i] = 0;
        }

        int a,b;
        cin >> a >> b;

        queue<int> q;
        q.push(a);
        p[a] = a;

        while(!q.empty()) {
            int f = q.front();
            q.pop();

            //D
            if(p[(f*2)%10000]==-1) {
                q.push((f*2)%10000);
                p[(f*2)%10000] = f;
                c[(f*2)%10000] = 'D';

                if((f*2)%10000 == b) break;
            }

            //S
            if(f>0 && p[f-1]==-1) {
                q.push(f-1);
                p[f-1] = f;
                c[f-1] = 'S';
                if(f-1 == b) break;
            } else if(f==0 && p[9999]==-1) {
                q.push(9999);
                p[9999] = f;
                c[9999] = 'S';
                if(9999 == b) break;
            }

            //L
            int l1 = (f%1000)*10;
            int l2 = f/1000;

            if(p[l1 + l2]==-1) {
                q.push(l1+l2);
                p[l1+l2] = f;
                c[l1+l2] = 'L';
                if(l1+l2==b) break;
            }

            //R
            int r1 = (f%10)*1000;
            int r2 = f/10;

            if(p[r1+r2]==-1) {
                q.push(r1+r2);
                p[r1+r2] = f;
                c[r1+r2] = 'R';
                if(r1+r2==b) break;
            }

        }

        stack<char> s;
        int index = b;

        while(index!=a) {
            s.push(c[index]);
            index = p[index];
        }

        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << '\n';
    
    }
}