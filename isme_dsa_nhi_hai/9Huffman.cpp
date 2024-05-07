#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    int freq;
    node*left;
    node* right;
    node(char c,int f){
        data=c;
        freq=f;
        left=nullptr;
        right=nullptr;
    }
};
class compare{
    public:
    bool operator()(node* x,node*y){
        return x->freq>y->freq;
    }
};

node* generateTree(priority_queue<node*,vector<node*>,compare>pq){
    
    while(pq.size()!=1){
        node* l=pq.top();
        pq.pop();
        node* r=pq.top();
        pq.pop();
        node* node1=new node('$',l->freq+r->freq);
        node1->left=l;
        node1->right=r;
        pq.push(node1);
    }
    return pq.top();
}
void printcodes(node* root,int arr[],int top){
    if(root->left){
        arr[top]=0;
        printcodes(root->left,arr,top+1);
    }
    if(root->right){
        arr[top]=1;
        printcodes(root->right,arr,top+1);
    }
    if(!root->left&&!root->right){
        cout<<root->data<<" : ";
        for(int i=0;i<top;i++) cout<<arr[i];
        cout<<endl;
    }
}
void huffman(char datas[],int freqs[],int size){
    priority_queue<node*,vector<node*>,compare>pq;
    for(int i=0;i<size;i++) {
        pq.push(new node(datas[i],freqs[i]));
    }
    node* root=generateTree(pq);
    int arr[100],top=0;
    printcodes(root,arr,top);
}
int main(){
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size=6;
    huffman(data,freq,size);
}