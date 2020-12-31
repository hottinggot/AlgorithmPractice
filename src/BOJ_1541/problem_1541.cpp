//잃어버린 괄호

#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main() {
    string sik;
    cin >> sik;

    int sum = 0;

    int alsum = 0;

    for(int i=0; i<sik.size();) {
        if(sik[i]=='-'){
            i++;
            string s;
            while(sik[i]!='-' && i<sik.size()){
                s+=sik[i++];
                if(sik[i]=='+' || sik[i]=='-' || i==sik.size()){
                    sum += stoi(s);
                    s.clear();
                }
            }
            alsum += (-sum);
            sum = 0;
        } else {
            string s;
            if(sik[i]=='+') i++;
            while(sik[i]!='-' && i<sik.size()){
                s+=sik[i++];
                if(sik[i]=='+' || sik[i]=='-' || i==sik.size()){
                    sum += stoi(s);
                    s.clear();
                }
            }
            alsum += sum;
            sum = 0;
        }
    }

    cout << alsum << '\n';


}