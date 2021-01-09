//행렬 제곱

#include<iostream>

using namespace std;

int mod = 1000;

void matmul(int n, int* mat1, int* mat2, int* result){
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            *(result + i*n + j) = 0;
            for(int k=0; k<n; k++) {
                *(result + i*n + j) += (*(mat1 + i*n+ k))*(*(mat2 + k*n + j));
            }
            *(result + i*n + j) %= mod; 
        }
    }
}

void matpow(int n, int *a, long long b, int *result) {
    if(b==1) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                *(result+n*i+j) = *(a+n*i+j)%mod;
            }
        }
        return;
    } else {
        matpow(n, a, b/2, result);
        int temp[n][n];
        matmul(n,result,result,(int*)temp);

        if(b&1) {
            int temp2[n][n];
            matmul(n,(int*)temp,a,(int*)temp2);
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    *(result+n*i+j) = temp2[i][j];
                }
            }
            
        } else {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    *(result+n*i+j) = temp[i][j];
                }
            }
        }

    }
}

int main() {
    int n;
    long long b;
    cin >> n >> b;

    int a[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    
    int result[n][n];
    matpow(n, (int*)a, b, (int*)result);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}