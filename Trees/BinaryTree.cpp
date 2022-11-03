#include <bits/stdc++.h>
using namespace std;

//-------node of Binary Tree-------------
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
//---------PreOrder Traversal ------------------
void preOrderTraversal (node *root) {
    if (root == NULL) 
        return;
    
    cout << root->data << ends;
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}
//---------PostOrder Traversal ------------------
void postOrderTraversal (node *root) {
    if (root == NULL) 
        return;
    
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root->data << ends;
}
//---------InOrder Traversal ------------------
void inOrderTraversal (node *root) {
    if (root == NULL) 
        return;
    
    inOrderTraversal(root -> left);
    cout << root->data << ends;
    inOrderTraversal(root -> right);
}
//---------Build Tree Level Order Traversal------------
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
//-----level Order Traversal---------------
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

//----Height of Binary Tree-----GFG-------
int heightOfTree(node* root)
{
    if(root == NULL)
        return 0;
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left, right) + 1;
}
//----Diameter of Tree----------GFG---
int diameterOfTree(node * root)
{
    if(root == NULL)
        return 0;
    int op1 = diameterOfTree(root->left);
    int op2 = diameterOfTree(root->right);
    int op3 = heightOfTree(root->left) + 1 + heightOfTree(root->right);

    return max(op1, max(op2, op3));
}
//------  1 2 3 4 5 6 7 -1 -1 -1 -1 8 -1 -1 -1 -1 -1 --------
int main()
{
    node* root;
    buildTreeLevelOrderT(root);
    levelOrderTraversal(root);
    int height = heightOfTree(root);
    cout<<"Height of Tree: "<<height<<endl;
    int diameter = diameterOfTree(root);
    cout<<"Diameter of Tree: "<<diameter<<endl;
    inOrderTraversal (root);cout<<endl;
    return 0;
}
