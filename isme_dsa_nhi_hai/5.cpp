#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node*left;
    node*right;
    int data;
    node(){
        left=NULL;
        right=NULL;
    }
    node(int x){
        left=NULL;
        right=NULL;
        data=x;
    }
};
void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder_i(node* root){
    if (root == NULL)
        return;
    stack<node*>s;
    node *x=root;
    while(!s.empty()||x!=NULL){
        while(x!=NULL){
            s.push(x);
            x=x->left;
        }
        x=s.top();
        s.pop();
        cout<<x->data<<" ";
        x=x->right;
    }
    cout<<endl;
}
void preorder_i(node* root){
    if (root == NULL)
        return;
    stack<node*>s;
    node*x=root;
    s.push(x);
    while(!s.empty()){
        x=s.top();
        s.pop();
        cout<<x->data<<" ";
        if(x->right) s.push(x->right);
        if(x->left) s.push(x->left);
    }
}
void postorder_i(node* root){
    if(root==NULL) return;
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    while(!s1.empty()){
        node* x=s1.top();
        s1.pop();
        s2.push(x);
        if(x->left) s1.push(x->left);
        if(x->right) s1.push(x->right);
    }
    while(!s2.empty()){
            node* t=s2.top();
            cout<<t->data<<" ";
            s2.pop();
        }
}
void levelorder(node* &root){
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* node1=q.front();
        q.pop();
        if(node1->left!=NULL) q.push(node1->left);
        if(node1->right!=NULL) q.push(node1->right);
        cout<<node1->data<<" ";
    }
}
node* insert_bst(int x,node* &root){
    if(root==NULL) return new node(x);
    if(x>root->data){
        root->right=insert_bst(x,root->right);
    }
    else {
        root->left=insert_bst(x,root->left);
    }
    return root;
}
int search(vector<int>inorder,int ins,int ine,int d){
    for(int i=ins;i<=ine;i++){
        if(inorder[i]==d) return i;
    }
}
node* construct_tree(vector<int>inorder,vector<int>preorder,int ins,int ine){
    static int preind=0;
    if(ins>ine) return NULL;
    node* t=new node(preorder[preind++]);
    if(ins==ine) return t;
    int inind=search(inorder,ins,ine,t->data);
    t->left=construct_tree(inorder,preorder,ins,inind-1);
    t->right=construct_tree(inorder,preorder,inind+1,ine);
    return t;
}
int main(){

}