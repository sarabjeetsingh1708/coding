//hardcode input
#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;

    }

};
Node* insertBST(Node *root, int val){
    if (root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left =insertBST(root->left,val);
   }
   else {
    root->right =insertBST(root->right,val);
   }
   return root;

}
int solve(Node *root,int& i,int k){
    if(root == NULL)
    return -1;
    int left=solve(root->left,i,k);
    if(left !=-1){
        return left;
    }
    i++;
    if(i==k)
    return root->data;

    return solve(root->right,i,k);


}
int main(){
    Node *root=NULL;
    root = insertBST(root,5);
    insertBST(root, 3);
    insertBST(root, 6);
    insertBST(root, 2);
    insertBST(root,4);
    int i=0;
    int k;
    cout<<"enter the kth value:";
    cin>>k;
    int answer=solve(root,i,k);
    cout<<answer<<endl;
}