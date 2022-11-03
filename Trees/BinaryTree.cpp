#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//-----Build Tree Level Order Traversal------------
void buildTreeLevelOrderT(node* &root)
{
    queue<node*> q;
    cout<<"Enter root data: ";
    int d;
    cin>>d;
    root = new node(d);
    q.push(root);
    while( !q.empty() ) {
        node* temp = q.front();
        q.pop();
        int data;
        cout<<"Enter data for left of "<<temp->data<<endl;
        cin>>data;
        if(data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout<<"Enter data for right of "<<temp->data<<endl;
        cin>>data;
        if(data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }

}
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp==NULL) {
            cout<<endl;
            if( !q.empty() ) {
                q.push(NULL);
            }
        } else {
            cout<<temp->data<<ends;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node* root;
    buildTreeLevelOrderT(root);
    levelOrderTraversal(root);

    return 0;
}
