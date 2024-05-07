#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
    
    node(){
        left=NULL;
        right=NULL;
            
    }
    node(int d){
        data=d;
        right=NULL;
        left=NULL;
    }

};
node* insert(node* root,int d){
    if(root==NULL)  root=new node(d);
    else if(d<root->data) root->left=insert(root->left,d);
    else {
        root->right=insert(root->right,d);
    }
    return root;
}

void re_preorder(node* root){
    
    if(root==NULL) return ;
    cout<<root->data<<" ";
    re_preorder(root->left);
    re_preorder(root->right); 
}  
void re_inorder(node* root){
    if(root==NULL) return ;
    re_inorder(root->left);
    cout<<root->data<<" ";
    re_inorder(root->right);
    

}
void re_postorder(node* root){
    if(root==NULL) return ;
    re_postorder(root->left);
    re_postorder(root->right); 
    cout<<root->data<<" ";
    
}
void level_order(node* root){
    if(root==NULL) return ;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        root=q.front();
        q.pop();
        cout<<root->data<<" ";
        if(root->left!=NULL) q.push(root->left);
        if(root->right!=NULL) q.push(root->right);
        
    }

}
void it_preorder(node* root){
    if(root==NULL) return ;
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }

}
void it_inorder(node* root){
    if(root==NULL) return ;
    stack<node*>st;
    while(true){
        if(root!=NULL){
            st.push(root);
            root=root->left;
        }
        else{
            if (st.empty()==true) break;
            root=st.top();
            st.pop();
            cout<<root->data<<" ";
            root=root->right;
        }

    }
}
void it_postorder(node* root ){
    if(root==NULL) return;
    stack<node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL) st1.push(root->left);
        if(root->right!=NULL) st1.push(root->right);

    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}
int height(node*root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
void mirror(node *root){
    if(root==NULL) return;
    swap(root->left,root->right);
    mirror(root->right);
    mirror(root->left);

}
node* clone(node* root){
    if(root==NULL) return NULL;
    node* root1=new node(root->data);
    root1->left=clone(root->left);
    root1->right=clone(root->right);
    return root1;

}
void erase(node* root){
        if(root==NULL) return;
        erase(root->left);
        erase(root->right);
        delete root;
}
int search(vector<int >inorder,int ins,int ine,int d){
    for(int i=ins;i<=ine;i++){
        if(inorder[i]==d) return i;
    }
}
node* construct_tree(vector<int>preorder,vector<int>inorder,int ins,int ine){
    static int preind=0;
    if(ins>ine)return NULL;
    node* t=new node(preorder[preind++]);
    if(ins ==ine) return t;
    int inind=search(inorder,ins,ine,t->data);
    t->left=construct_tree(preorder,inorder,ins, inind-1);
    t->right=construct_tree(preorder,inorder,inind+1,ine);
    return t;
}

int main(){
    cout<<"BST"<<endl;
    int d;
    node*root=NULL;
    cout<<"enter no. of nodes:"<<endl;
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        //cout<<"enter node to be inserted:"<<endl;
        cin>>d;
        root=insert(root,d);
    }

    cout<<"....menu...."<<endl;
    cout<<"1.recursive preorder "<<endl;
    cout<<"2.recursive inorder "<<endl;
    cout<<"3.recursive postorder "<<endl;
    cout<<"4.level order"<<endl;
    cout<<"5.iterrative preorder"<<endl;
    cout<<"6.iterative inorder"<<endl;
    cout<<"7.itertaive postorder"<<endl;
    cout<<"8.mirror image"<<endl;
    cout<<"9.clone"<<endl;
    cout<<"10.erase"<<endl;
    cout<<"11.height "<<endl;
    cout<<"0.EXIT"<<endl;
    int choice;
    
    while(true){
        cout<<"enter choice:"<<endl;
        cin>>choice;
        if(choice==1){
             re_preorder(root);
             cout<<endl;
             }
        else if(choice==2){
            re_inorder(root);
            cout<<endl;
        }
        else if(choice==3) {
            re_postorder(root);
            cout<<endl;
            }
        else if(choice==4) {
            level_order(root);
            cout<<endl;
            }
        else if(choice==5) {
            it_preorder(root);
            cout<<endl;
            } 
        else if(choice==6) {
            it_inorder(root);
            cout<<endl;
            }
        else if(choice==7) {
            it_postorder(root);
            cout<<endl;
            }
        else if(choice==8) {
            mirror(root);
            cout<<endl;
            } 
        else if(choice==9) {
            clone(root);
            cout<<endl;
            } 
        else if(choice==10) {
            erase(root);
            cout<<endl;
            }
        else if(choice==11) {
            height(root);
            cout<<endl;
            }         
        else break;
    }
    
    


}