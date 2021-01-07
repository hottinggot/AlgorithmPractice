//최대 힙

#include<iostream>
#include<algorithm>

using namespace std;

void insert_max_heap(int* arr, int index, int x) {
    arr[index] = x;
    while(index/2>0){
        if(arr[index] > arr[index/2]){
            swap(arr[index], arr[index/2]);
        }
        index /= 2;
    }
}

int delete_max_heap(int* arr, int size) {
    int index = 1;
    if(size == 1) return 0;
    int ret = arr[1];
    arr[1] = arr[size-1];
    while(1) {
        int maxi;
        int maxidx;

        if(index*2+1<size-1){
            if(arr[index*2] <= arr[index*2+1]){
                maxi = arr[index*2+1];
                maxidx = index*2+1;
            } else {
                maxi = arr[index*2];
                maxidx = index*2;
            }
        } else if(index*2<size-1) {
            maxi = arr[index*2];
            maxidx = index*2;
        } else  {
            return ret;
        }

        if(arr[index] < maxi){
            swap(arr[index], arr[maxidx]);
            index = maxidx; 
        }
        else {
            break;
        }
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr_heap[n+1];
    int index = 1;

    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;

        if(x==0) {
            cout << delete_max_heap(arr_heap, index) << '\n';
            if(index>1) index--;
        } else {
            insert_max_heap(arr_heap, index, x);
            index++;
        }
    }
}