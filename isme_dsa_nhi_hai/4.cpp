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
int height(node* root){
    if(root==NULL){
        return 0;
    }
    else {
        int hl=height(root->left);
        int hr=height(root->right);
        return(max(hl,hr)+1);
    }
}
node* clone(node*root){
    if(root==nullptr){
        return nullptr;
    }
    node* x=new node(root->data);
    x->left=clone(root->left);
    x->right=clone(root->right);
    return x;
}
node* mirrorImg(node* &root){
    if(root==nullptr){
        return nullptr;
    }
    node* x=new node(root->data);
    x->left=mirrorImg(root->right);
    x->right=mirrorImg(root->left);
    
    return x;
} 

int main(){
    int n,d;cin>>n;
    node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>d;
        root=insert_bst(d,root);
    }
    node*root1=mirrorImg(root);
    inorder(root1);
    
   return 0; 
}

/*
			10
	5				15
		7				23
*/

