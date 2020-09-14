#include<iostream>
#include<string>

using namespace std;

int queue[10000];
int p = -1;

void push(int x){
    p++;
    queue[p] = x;
}

int empty(){
    if(p<0) return 1;
    else return 0;
}

int size(){
    return p+1;
}

int pop(){
    int a = -1;
    if(!empty()){
        a = queue[0];
        for(int i = 0; i<size(); i++){
            queue[i] = queue[i+1];
        }
        p--;
    }
    return a;
}

int front(){
    if(!empty())
        return queue[0];
    else return -1;
}

int back(){
    if(!empty()) return queue[p];
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(cmd == "pop"){
            cout << pop() << '\n';
        }
        else if(cmd == "size"){
            cout << size() << '\n';
        }
        else if(cmd == "empty"){
            cout << empty() << '\n';
        }
        else if(cmd == "front"){
            cout << front() << '\n';
        }
        else if(cmd == "back"){
            cout << back() << '\n';
        }
    }

}