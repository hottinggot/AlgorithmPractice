//단어 수학
//https://ideone.com/Tl6klp

#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

vector<pair<int, string>> words;
int arr[26];

int go(int index, int n){
    int len = words[index].first;

    for(int i = index; words[i].first==len; i--){
        arr[words[i].second[0] - 'A'] = n;
    }

}

int main () {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        string word;
        cin >> word;

        words.push_back({word.length(), word});
    }

    sort(words.begin(), words.end());

}