#include<bits/stdc++.h>
using namespace std;
static int indx=-1;
class Node{
    public :
    int data;
    Node*left;
    Node*right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};  
class BT{

};
Node *buildtree(vector<int>preorder){
    indx++;
    if(preorder[indx]==-1){
        return NULL;
    }
    Node* root=new Node(preorder[indx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;

}
void preorder_traverse(Node * root){
    if(root==NULL){return;}
    cout<< root->data;
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}
void inorder_traverse(Node* root){
    if(root==NULL){return;}
    inorder_traverse(root->left);
    cout<<root->data;
    inorder_traverse(root->right);
}
void postOrder_traverse(Node* root){
    if(root==NULL){
        return;
    }
    postOrder_traverse(root->left);
    postOrder_traverse(root->right);
    cout<<root->data; 
}

void levelOrder(Node * root){
    queue<Node*>q;
    q.push(root);
    while(q.size()!=0){
        Node*curr=q.front();
        q.pop();
        cout<<curr->data;
        if(curr->left!=NULL){q.push(curr->left);}
        if(curr->right!=NULL){q.push(curr->right);}

    }
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

}