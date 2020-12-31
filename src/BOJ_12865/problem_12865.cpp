//평범한 배낭

#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> list;

int maxi;

int go(int index, int k, int weight, int value){

    if(index>=list.size()) return 0;

    cout << "index: " << index << " weight: " << weight << " value: " << value << " max: " << maxi << '\n';

    for(int i=index; i<list.size(); i++) {
        value = list[i].second;
        if(list[i].first<=k) {
            if(weight + list[i].first<=k){
                if(maxi < value) maxi = value;
                go(index+1, k, weight+list[i].first, value);
                value = value +list[i].second;
                
            }else{
                cout << "return : " << weight+list[i].first << '\n';
                return 0;
            }
            
        }
    }
}


int main() {
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n ;i++) {
        int w, v;
        cin >> w >> v;

        list.push_back({w,v});
    }

    go(0,k,0,0);
    cout << maxi << '\n';
}