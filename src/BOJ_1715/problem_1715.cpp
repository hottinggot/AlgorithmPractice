//카드 정렬하기

#include<iostream>
#include<queue>

using namespace std;

int main() {
    int n;
    priority_queue<int> pq;

    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        pq.push(-x);
    }

    if(n==1) {
        cout << 0 << '\n';
        pq.pop();
        return 0;
    }

    int sum = 0;

    while(1) {
        int x = -pq.top();
        pq.pop();
        int y = -pq.top();
        pq.pop();

        sum += x+y;

        if(pq.empty()) break;

        int t = x+y;
        pq.push(-t);
    }

    cout << sum << '\n';
}