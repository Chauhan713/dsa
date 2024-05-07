void inOrder(node* root, vector<int>& sol)
{
    if (root == NULL)
        return;
    inOrder(root->left, sol);
    sol.push_back(root->data);
    inOrder(root->right, sol);
}
void preOrder(node* root, vector<int>& sol)
{
    if (root == NULL)
        return;
    sol.push_back(root->data);
    preOrder(root->left, sol);
    preOrder(root->right, sol);
}
bool equalCheck(node *root,node *root2){
    vector<int> v1;
    vector<int> v2;

    inOrder(root,v1);
    inOrder(root2,v2);

    if(v1!=v2) return false;
    v1.clear();
    v2.clear();

    preOrder(root,v1);
    preOrder(root2,v2);
    if(v1!=v2) return false;
    return true;
}
