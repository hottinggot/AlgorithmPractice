//히스토그램에서 가장 큰 직사각형

#include<iostream>

using namespace std;

long long area[100001];

void cal(int start, int mid, int end, long long h[]){

        int x1 = 0;
        long long temp1 = area[mid];
        for(int a = mid; a>=start; a--) {
            if(temp1 == area[a]) x1++;
            else break;
        }
        int height1 = temp1/x1;

        int x2 = 0;
        long long temp2 = area[mid+1];
        for(int a = mid+1; a<=end; a++) {
            if(temp2 == area[a]) x2++;
            else break;
        }
        int height2 = temp2/x2;

        if(height1<=height2) {
            int comh = height1;
            long long maxarea = comh*(x2+x1);
            int before = comh;
            long long beforearea = maxarea;
            int index=mid-x1+1;
            int beforeindex = index;
            for(int i=mid-x1+1; i<=mid+x2; i++) {
                if(h[i]<comh) {
                    comh = before;
                    maxarea = beforearea;
                    index = beforeindex;
                }
                if(h[i]>comh) {
                    before = comh;
                    comh = h[i];
                    long long t = (mid+x2-i+1) * comh;
                    beforearea = maxarea;
                    if(t>maxarea) {
                        //beforearea = maxarea;
                        maxarea = t;
                        beforeindex = index;
                        index = i;
                    }
                }
            }
            //cout << '\n' << comh << ' ' << index << ' ' << maxarea << '\n';

            for(int i=index; i<=mid+x2; i++) {
                area[i] = maxarea;
            }
        } else {
            int comh = height2;
            long long maxarea = comh*(x2+x1);
            int before = comh;
            long long beforearea = maxarea;
            int index=mid+x2;
            int beforeindex = index;
            for(int i=mid+x2; i>=mid-x1+1; i--) {
                if(h[i]<comh) {
                    comh = before;
                    maxarea = beforearea;
                    index = beforeindex;
                }
                if(h[i]>comh) {
                    before = comh;
                    comh = h[i];
                    long long t = (i-(mid-x1)) * comh;
                    beforearea = maxarea;
                    if(t>maxarea) {
                        //beforearea = maxarea;
                        maxarea = t;
                        beforeindex = index;
                        index = i;
                    }
                }
               
            }
            //cout << '\n' << comh << ' ' << index << ' ' << maxarea << '\n';

            for(int i=index; i>=mid-x1+1; i--) {
                area[i] = maxarea;
            }
        }
}

void devide(int start, int end, long long h[]) {
    int mid;
    if(start < end) {
        mid = (start + end)/2;
        devide(start, mid, h);
        devide(mid+1, end, h);
        cal(start, mid, end, h);
    }
}

int main() {
    while(1) {
        int n;
        cin >> n;

        if(n==0) break;

        long long h[n];
        for(int i=0; i<n; i++) {
            cin >> h[i];
            area[i] = h[i];
        }

        devide(0, n-1, h);

        long long maxi = 0;
        for(int i=0; i<n; i++) {
            //cout << area[i] << ' ';
            if(area[i] > maxi) maxi = area[i];
        }

        cout << maxi << '\n';
    }
}