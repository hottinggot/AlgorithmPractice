//암호 만들기

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool check(string str) {
    int mo=0;
    int ja=0;

    for(int i=0 ; i<str.length(); i++) {
        if(str.at(i)=='a' || str.at(i)=='e' || str.at(i)=='i' || str.at(i)=='o' || str.at(i)=='u' ){
            mo++;
        }
        else ja++;
    }

    if(mo>=1 && ja>=2) return true;
    else return false;
}
void go(int l, int c, string ans, string s, int index){
    if(ans.length()==l) {
        if(check(ans)){
            cout << ans << '\n';
        }
        return;
    }

    if(index>=c) return;

    go(l,c,ans+s.at(index),s,index+1);
    go(l,c,ans,s,index+1);

}

int main() {
    int l, c;
    cin >> l >> c;

    string s="";

    for(int i=0; i<c; i++) {
        char a;
        cin >> a;
        s+=a;
    }

    sort(s.begin(), s.end());

    go(l,c,"",s,0);


}