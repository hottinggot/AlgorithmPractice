//알 수 없는 문장

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<string> wordstr;
vector<string> wordsort;
int D[50];


int cost(string s1, string s2){
    int cnt = 0;
    for(int i=0; i<s1.length(); i++) {
        if(s1[i]!=s2[i]) cnt++;
    }
    return cnt;
}

void makewordsort(vector<string> v){
    for(int i=0; i<v.size(); i++) {
        sort(v[i].begin(), v[i].end());
        wordsort.push_back(v[i]);
    }
}

int findword(string s, int n){
    if(D[n] >= -1) return D[n];

    if(n==0) return 0;

    int mini = -1;

    for(int i=0; i<wordstr.size(); i++) {
        int len = wordstr[i].length();
        if(len > n) continue;

        string tstr;
        for(int j=0; j<len; j++) {
            tstr += s[j];
        }
        string tstrsort = tstr;
        sort(tstrsort.begin(), tstrsort.end());

        if(tstrsort.compare(wordsort[i])==0){

            string newstr;
            for(int j=len; j<s.length(); j++) {
                newstr += s[j];
            }

            int result;
            int temp = findword(newstr, n-len);
            if(temp == -1) continue;
            else result = cost(wordstr[i], tstr) + temp;

            if(mini == -1 || mini > result)
                mini = result;
        }
    }

    D[n] = mini;

    return D[n];

}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    for(int i=0; i<=50; i++) D[i] = -2;

    for(int i=0; i<n; i++) {
        string word;
        cin >> word;
        wordstr.push_back(word);
    }

    makewordsort(wordstr);
    findword(s, s.length());
    cout << D[s.length()] << '\n';
}