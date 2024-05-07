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
    if(root==NULL) return;
    stack<node*>s;
    node* t=root;
    while(!s.empty()||t){
        while(t!=NULL){
            s.push(t);
            t=t->left;
        }
        t=s.top();
        s.pop();
        cout<<t->data;
        t=t->right;
    }
}
void preorder_i(node* root){
    stack<node*>s;
    s.push(root);
    while(!s.empty()){
        node* t=s.top();
        s.pop();
        cout<<t->data<<" ";
        if(t->right) s.push(t->right);
        if(t->left) s.push(t->left);
    }
}
void postorder_i(node* root){
    stack<node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        node* t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left) s1.push(t->left);
        if(t->right) s1.push(t->right);
    }
    while(!s2.empty()) {
        node* t=s2.top();
        s2.pop();
        cout<<t->data<<" ";
    }
}
int height(node* root){
    if(root==NULL) return -1;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
node* clone(node* root){
    if(root==NULL) return NULL;
    node* t=new node(root->data);
    t->left=clone(root->left);
    t->right=clone(root->right);
    return t;
}
node* mirrorImg(node* &root){
    if(root==nullptr){
        return nullptr;
    }
    node* x=new node(root->data);
    x->left=clone(root->right);
    x->right=clone(root->left);
    
    return x;
} 
node* constructTree(vector<int>inorder,vector<int>preorder,int ins,int ine){
    static int prein=0;
    if(ins>ine) return NULL;
    if(ins==ine) return new node(preorder[prein++]);
    node* t=new node(preorder[prein++]);
    int inind;
    for(int i=ins;i<=ine;i++){
        if(inorder[i]==t->data) {inind=i;break;}
    }
    t->left=constructTree(inorder,preorder,ins,inind-1);
    t->right=constructTree(inorder,preorder,inind+1,ine);
    return t;
}
node* deleteNode(node* root,int key){
    if(root==NULL) return NULL;
    if(key<root->data) deleteNode(root->left,key);
    else if(key>root->data) deleteNode(root->right,key);
    if(root->left==NULL){
        node*t=root->right;
        delete root;
        return t;
    }
    else if(root->right==NULL){
        node*t=root->left;
        delete root;
        return t;
    }
    else {
        node* parent=root;
        node* curr=root->right;
        while(curr->left){
            parent=curr;
            curr=curr->left;
        }
        if(parent!=root){
            parent->left=curr->right;
        }
        else parent->right=curr->right;
        root->data=curr->data;
        delete curr;
        return root;

    }
}
int main(){

}