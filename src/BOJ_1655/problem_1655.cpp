//가운데를 말해요

#include<iostream>
#include<queue>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> bignums, smallnums; 

    int x;
    cin >> x;

    int mid = x;
    smallnums.push(x);

    cout << smallnums.top() << '\n';

    for(int i=1; i<n ;i++){
        cin >> x;
        if(x>mid) {
            bignums.push(-x);
        } else {
            smallnums.push(x);
        }

        if(i%2==0 && bignums.size() > smallnums.size()){
            int t = bignums.top() * (-1);
            bignums.pop();
            smallnums.push(t);
        } else if (i%2==1 && smallnums.size() > bignums.size()){
            int t = smallnums.top();
            smallnums.pop();
            bignums.push(-t); 
        }

        mid = smallnums.top();
        cout << mid << '\n';

    }
}