
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node( int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void preorderTraversal(node* root){
    if(root==NULL)
     return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right); 
}
void inorderTraversal(node* root){
    if(root==NULL)
     return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);                           
}
void postorderTraversal(node* root){
    if(root==NULL)
     return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" "; 
}
vector<vector<int>> levelorderTraversal(node* root){
    vector<vector<int>> ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            node* node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
   node* root=new node(1);
   root->left=new node(2);
   root->left->left=new node(3);
   root->left->left->right=new node(4);
   root->left->left->right->right=new node(5);
   root->left->left->right->right->right=new node(6);
   root->right=new node(7);
   root->right->left=new node(8);
   preorderTraversal(root);
   cout<<endl;
   inorderTraversal(root);
   cout<<endl;
   postorderTraversal(root);
   cout<<endl;
   vector<vector<int>> ans=levelorderTraversal(root);
   for(auto it:ans){
    for(auto it1:it){
        cout<<it1<<" ";
    }
    cout<<endl;
   }
}
