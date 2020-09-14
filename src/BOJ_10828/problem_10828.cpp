#include<iostream>
#include<string>

using namespace std;

int stack[10000];
int p = -1;

void push(int x){
    p++;
    stack[p] = x;
}

int empty(){
    if(p<0){
        return 1;
    } else {
        return 0;
    }
}

int pop(){
    if(empty()) return -1;
    else {
        p--;
        return stack[p+1];
    }
}

int size(){
    return p+1;
}



int top(){
    if(empty()) return -1;
    else{
        return stack[p];
    }
}

int main(){
    int n; //명령의 수
    scanf(" %d", &n);

    string str;

    for(int i = 0; i<n; i++){
        cin >> str;
        if(str.compare("push") == 0){
            int x;
            cin >> x;
            push(x);
        } else if(str.compare("pop") == 0){
            cout << pop() << "\n";
        } else if(str.compare("size") == 0){
            cout << size() << "\n";
        } else if(str.compare("empty") == 0){
            cout << empty() << "\n";
        } else if(str.compare("top") == 0){
            cout << top() << "\n";
        }
    }
    
}