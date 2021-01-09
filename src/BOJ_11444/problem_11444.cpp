//피보나치 수 6

#include<iostream>

using namespace std;

int mod = 1000000007;

void mul(long long *mat1, long long *mat2, long long *result) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++){
            *(result + 2*i + j) = 0;
            for(int k=0; k<2; k++) {
                *(result + 2*i + j) += (*(mat1 + 2*i + k))*(*(mat2 + 2*k + j))%mod;
                *(result + 2*i + j) %= mod;
            }
            
        }
    }
}

void fibo(long long n, long long *arr, long long *result) {
    if(n==1) {
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                *(result + 2*i +j) = *(arr + 2*i +j)%mod;
            }
        }
        return;
    } else {
        long long temp[2][2];
        fibo(n/2, arr, (long long*)temp);

        long long even[2][2];
        mul((long long*)temp, (long long*)temp, (long long*)even);

        if(n&1){
            long long odd[2][2];
            mul((long long*)even, arr, (long long*)odd);
            for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {
                    *(result + 2*i +j) = odd[i][j];
                }
            }

        } else {
            for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {
                    *(result + 2*i +j) = even[i][j];
                }
            }
        }
    }
}

int main() {
    long long n;
    cin >> n;

    long long arr[2][2] = {1, 1, 1, 0};
    long long result[2][2];

    fibo(n, (long long*)arr, (long long*)result);

    cout << result[0][1] << '\n';

}