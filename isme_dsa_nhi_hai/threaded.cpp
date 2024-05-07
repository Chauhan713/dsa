// Write a C++ program to inorder threaded binary search tree with n nodes 
// and implement following operations   
//  1.Insert a new node 
//  2. Inorder traversal 

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;
    bool lThread;
    bool rThread;

    node(){
           left=right=nullptr;
           lThread=rThread=true;
    }
    node(int val){
        data =val;
        left=right=nullptr;
        lThread=rThread=true;
    }
};

void insert(int key,node*root)
{
      node *p=new node(key);

      if(root->left==NULL){
            root->left=p;
            p->left=root;
            p->right=root;
            root->lThread=free;
      }
      else
      {
            node *temp=root->left;
            while(true){
                  if(key<temp->data){
                       if(temp->lThread==true){
                            p->left=temp->left;
                            temp->left=p;
                            temp->lThread=false;
                            p->right=temp;
                            return;
                       }
                       else{
                           temp=temp->left;
                       }
                  }
                  else
                  {
                        if(temp->rThread==true){
                               p->right=temp->right;
                               temp->right=p;
                               temp->rThread=false;
                               p->left=temp;
                               return;
                         }else{
                            temp=temp->right;
                         }
                  }
            }
      }
}

void inorder(node* root){
    cout<<"Inorder : ";

     node *current=root->left;

     while(current!=root){

          while(current->lThread==false){
               current=current->left;
          }

          cout<<current->data<<" ";

          if(current->rThread==false){
            current=current->right;
          }
          else{
               while(current->rThread==true && current->right!=root){
                 
                 current=current->right;
                 cout<<current->data<<" ";

              }
              current=current->right;
          }
     }
     cout<<endl;
}

int main(){
    node *dummy=new node(999);
 
    insert(6, dummy);
    insert(3, dummy);
    insert(8, dummy);
    insert(1, dummy);
    insert(5, dummy);
    insert(7, dummy);
    insert(11, dummy);
    insert(9, dummy);
    insert(13, dummy);
    inorder(dummy);
}

