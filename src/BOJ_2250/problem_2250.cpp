//트리의 높이와 너비

#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int left;
    int right;
};

Node a[10001];
int ord[10001];
int ct = 1;
int cnt[10001];
int check[10001];

void inorder(int x){
    if(x==-1) return;
    inorder(a[x].left);
    ord[x] = ct++;
    inorder(a[x].right);
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int x, y, z;
        cin >> x >> y >> z;

        a[x].left = y;
        a[x].right = z;

        if(y!=-1) cnt[y] +=1;
        if(z!=-1) cnt[z] +=1;
    }

    int root=0;

    for(int i=1; i<=n; i++){
        if(cnt[i]==0) {
            root=i;
        }
    }

    inorder(root);

    queue<int> q;

    q.push(root);
    check[root] = 1;

    int depth=0;

    while(!q.empty()){
        int f = q.front();
        q.pop();
        depth = check[f];

        if(a[f].left!=-1 && check[a[f].left]==0){
            check[a[f].left] = check[f] + 1;
            q.push(a[f].left);
        }
        if(a[f].right!=-1 && check[a[f].right]==0){
            check[a[f].right] = check[f] + 1;
            q.push(a[f].right);
        }
    }

    int ans=0;
    int d=1;

    for(int i=1; i<=depth; i++){
        int min=-1;
        int max=-1;
        for(int j=1; j<=n; j++) {
            if(check[j]==i){
                if(min==-1 || ord[j]<ord[min]) min=j;
                if(max==-1 || ord[j]>ord[max]) max=j;
            }
        }
        if(ord[max]-ord[min]>ans){
            ans=ord[max]-ord[min];
            d=check[min];
        }
    }

    cout << d << ' ' << ans+1 << '\n';

    

}