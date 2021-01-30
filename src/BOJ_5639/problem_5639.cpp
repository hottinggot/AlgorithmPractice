//이진 검색 트리

#include<iostream>

using namespace std;

int arr[10001];

struct Node{
    int data;
    Node *left;
    Node *right;
};

void print(Node* node) {
    if(node != NULL) {
        print(node->left);
        print(node->right);
        cout << node->data << '\n';
    }
}

int main() {
    int n;
    int index = 0;
    while(cin >> n){
        arr[index++] = n;
    }

    Node* root = (Node*)malloc(sizeof(Node));
    root->data = arr[0];
    root->left = NULL;
    root->right = NULL;

    for(int i=1; arr[i]!=0; i++) {
        Node* nt = (Node*)malloc(sizeof(Node));
        nt->data = arr[i];
        nt->left = NULL;
        nt->right = NULL;

        Node* temp = root;

        while(1) {
            if(arr[i]<temp->data) {
                if(temp->left != NULL) temp = temp->left;
                else {
                    temp->left = nt;
                    break;
                }
            } else {
                if(temp->right != NULL) temp = temp->right;
                else {
                    temp->right = nt;
                    break;
                }
            }
        }
    }

    print(root);
}