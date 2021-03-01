//AC

#include<iostream>
#include<deque>
#include<cstdlib>
#include<sstream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string p;
        cin >> p;
        int n;
        cin >> n;
        string str;
        cin >> str;
        deque<int> dq;
        vector<string> result;

        string temp = "";
        for(int i=0; i<str.length(); i++) {
            if(str[i]==' ' || str[i]==',' || str[i]=='[' || str[i]==']') {
                result.push_back(temp);
                temp = "";
            } else {
                temp += str[i];
            }
        }

        for(int i=0; i<result.size(); i++) {
            if(isdigit(result[i][0])) dq.push_back(atoi(result[i].c_str()));
        }

        bool x = 0;
        bool error = 0;
        for(int i=0; i<p.length(); i++) {
            if(p[i]=='R') {
                x = !x;
            }

            if(p[i]=='D') {
                if(dq.empty()) {
                    cout << "error\n";
                    error = 1;
                    break; 
                }
                if(x==0) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            }
        }
        if(error==0) {
            cout << '[';
            if(x==0) {
                
                while(!dq.empty()) {
                    if(dq.size()==1) {
                        cout << dq.front();
                        dq.pop_front();
                    } else {
                        cout << dq.front() << ",";
                        dq.pop_front();
                    }
                    
                }
                
            } else {
                while(!dq.empty()) {
                    if(dq.size()==1) {
                        cout << dq.back();
                        dq.pop_back();
                    } else {
                        cout << dq.back() << ",";
                        dq.pop_back();
                    }
                    
                }
            }
            cout << "]\n";
        }    
    }
}