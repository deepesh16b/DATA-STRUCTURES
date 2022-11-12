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

//----Diameter of Tree---O(n^2)-----GFG---
int diameterOfTree(node * root)
{
    if(root == NULL)
        return 0;
    int op1 = diameterOfTree(root->left);
    int op2 = diameterOfTree(root->right);
    int op3 = heightOfTree(root->left) + 1 + heightOfTree(root->right);

    return max(op1, max(op2, op3));
}
int ans = 0;
//----Diameter of Tree---O(n)----optimized---
int diameterOfTreeFast(node * root)  
{
    //---it will actually return the height of tree
    //---But also update the global variable 'ans' which is the diameter
    if(root == NULL)
        return 0;
    int left = diameterOfTreeFast(root->left);
    int right = diameterOfTreeFast(root->right);
    ans = max(ans, left + right + 1);
    return max(left, right) + 1;
}

//----main fun for Check for balanced tree (gfg)----------
pair<bool, int> checkBalancedTreeMain(node* root)
{
    if(root == NULL)
    {
        pair<bool, int> p(true, 0);
        return p;
    }
    pair<bool, int> left, right, ans;
    left = checkBalancedTreeMain(root->left); //-- < true/false , height >
    right = checkBalancedTreeMain(root->right);
    bool cond = (abs(left.second-right.second)<= 1);
    if(left.first && right.first && cond)
        ans.first = true;
    else
        ans.first = false;
    ans.second = max(left.second, right.second) + 1; // ---height of this subtree
    return ans;
}

//----- check balanced tree----gfg------
bool checkBalancedTree(node* root)
{
    return checkBalancedTreeMain(root).first;
}

//-----Check for Identical Trees ---
bool checkIdenticalTrees(node* r1, node* r2)
{
    if(r1 == NULL && r2 == NULL)
        return true;
    if(r1 == NULL && r2 != NULL)
        return false;
    if(r1 != NULL && r2 == NULL)
        return false;
    
    bool left = checkIdenticalTrees(r1->left, r2->left);
    bool right = checkIdenticalTrees(r1->right, r2->right);
    if(r1->data == r2->data && left && right)
        return true;
    return false;
}

// if tree is Sum Tree, return true ,else false
pair<bool, int> SumTree(node* root)
{
    if(!root)
    {
        pair<bool, int> p(true, 0);
        return p;
    }
    if(!root->left && !root->right)
    {
        pair<bool, int> p(true, root->data);
        return p;
    }
    pair<bool, int> left, right, ans;
    left = SumTree(root->left);
    right = SumTree(root->right);
    bool cond = ((left.second + right.second) == root->data);
    if(cond && left.first && right.first)
        ans.first = true;
    else
        ans.first = false;
    ans.second = 2*root->data;
    return ans;
}
bool isSumTree(node* root)
{
        // Your code here
        return SumTree(root).first;
}

//----Zig-Zag Tree Traversal----------------------
void zigzagTraversal(node*root)
{
    if(root == NULL)
        return ;
    queue<node*> q;
    q.push(root);
    vector<int> result;
    bool leftToRight = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++)
        {
            node* frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;
            if(frontNode->left)
                q.push(frontNode->left);
            if(frontNode->right)
                q.push(frontNode->right);
        }
        for(auto i: ans)
            result.push_back(i);
        leftToRight = !leftToRight;
    }
    for(auto i:result)
        cout<<i<<" ";
    cout<<endl;
}

//----Boundary Traversal of Tree-----------------
void leftTree(node* root, vector<int> &ans)
{
    if( root == NULL )
        return;
    if(root->right && root->left) //--avoid leaf node to print
        ans.push_back(root->data);
    if(root->left)
        leftTree(root->left, ans);
    else if(root->right)
        leftTree(root->right, ans);
}
void leafNodes(node* root, vector<int> &ans)
{
    if(root == NULL)
        return;
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
    if(root->right == NULL && root->left == NULL)
        ans.push_back(root->data);
}
void rightTree(node* root, vector<int> &ans)
{
    if(root == NULL)
        return;
    if(root->right)
        rightTree(root->right, ans);
    else if(root->left)
        rightTree(root->left, ans);
    if(root->right && root->left) //--avoid leaf node to print
        ans.push_back(root->data);
}
void boundaryTraversal(node* root)
{
    if(root == NULL)
        return;
    vector<int> ans;
    ans.push_back(root->data); //--root node--

    leftTree(root->left, ans); //--left boundary
    leafNodes(root, ans); //--bottom(leaf node) boundary
    rightTree(root->right, ans);//--right boundary
    
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
}

//---Vertical Traversal of Tree---------------
void verticalTraversal(node* root)
{
    vector<int> ans;
    if(root == NULL)
        return;
    map<int, map<int, vector<int> > > mapping; 
    //--hd = horizontal-distance, lvl = level, ans = final answer list
    //--map<hd, map<lvl, vector<int> ans>> = mapping
    queue< pair< node*, pair<int, int> > > q; 
    //--queue< node* , pair(hd, lvl) >
    q.push(make_pair(root, make_pair( 0 , 0 )));

    while( !q.empty())
    {
        pair< node*, pair<int, int> > temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        //now insert new node w.r.t. horiz.dist. & level
        mapping[hd][lvl].push_back(frontNode->data);

        if(frontNode->left)
            q.push( make_pair( frontNode->left, make_pair( hd-1, lvl+1 ) ) );
        if(frontNode->right)
            q.push( make_pair( frontNode->right, make_pair( hd+1, lvl+1 ) ) );
        

    }
    for(auto i: mapping)
    {
        for(auto j: i.second)
        {
            for(auto k: j.second)
            {
                ans.push_back(k);
            }
        }
    }
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;

}

//------ Top view of tree--------------
void topViewOfTree( node* root)
{
    vector<int> ans;
    if(root == NULL)
        return;
    queue< pair< int, node*>> q;
    map< int, int> mapping; // <hd, value>
    q.push(make_pair(0, root));
    while(!q.empty())
    { 
        pair<int, node*> temp = q.front();
        q.pop();
        int hd= temp.first;
        node* frontNode= temp.second;
        if(mapping.find(hd) == mapping.end())
            mapping [hd] = frontNode->data;
        if(frontNode->left)
            q.push(make_pair(hd-1, frontNode->left));
        if(frontNode->right)
            q.push(make_pair(hd+1, frontNode->right));
 
    }
    for(auto i: mapping)
        ans.push_back(i.second);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
}

//-----bottom View Of Tree--------------------
void bottomViewOfTree( node* root)
{
    vector<int> ans;
    if(root == NULL)
        return;
    queue< pair< int, node*>> q;
    map< int, int> mapping; // <hd, value>
    q.push(make_pair(0, root));
    while(!q.empty())
    { 
        pair<int, node*> temp = q.front();
        q.pop();
        int hd= temp.first;
        node* frontNode= temp.second;
        // if(mapping.find(hd) == mapping.end())
            mapping [hd] = frontNode->data;
        if(frontNode->left)
            q.push(make_pair(hd-1, frontNode->left));
        if(frontNode->right)
            q.push(make_pair(hd+1, frontNode->right));
 
    }
    for(auto i: mapping)
        ans.push_back(i.second);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
}
//------  1 2 3 4 5 6 7 -1 -1 -1 -1 8 -1 -1 -1 -1 -1 --------
//------  1 2 3 4 5 -1 -1 -1 -1 -1 -1  ------------
int main()
{
    node* root;
    buildTreeLevelOrderT(root);
    levelOrderTraversal(root);
    
    int height = heightOfTree(root);
    cout<<"Height of Tree: "<<height<<endl;
    
    int diameter = diameterOfTree(root);
    cout<<"Diameter of Tree: "<<diameter<<endl;
    
    diameterOfTreeFast(root);
    cout<<"Diameter of Tree : "<<ans<<endl;
    
    inOrderTraversal (root);cout<<endl;
    cout<<checkBalancedTree(root)<<endl;

    cout<<"Check for Sum Tree: "<<isSumTree(root)<<endl;
    
    //-------------
    node* r1, * r2;
    buildTreeLevelOrderT(r1);
    levelOrderTraversal(r1);
    buildTreeLevelOrderT(r2);
    levelOrderTraversal(r2);
    cout<<checkIdenticalTrees(r1, r2)<<endl;
    //-------------

    zigzagTraversal(root);
    boundaryTraversal(root);
    verticalTraversal(root);
    topViewOfTree( root);
    bottomViewOfTree(root);
    return 0;
}
