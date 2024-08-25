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

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;
    
    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else if (root->data < key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        Node* temp =root->right;
        while(temp->left != nullptr){
            temp = temp->left;
        }
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if(root !=nullptr){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);  
    }
}
void postorder(Node* root) {
    if(root !=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

}

int height(Node* root) {
    if (root == nullptr)
        return -1; 
    int leftnode = height(root->left);
    int rightnode = height(root->right);
    
    
    if(leftnode> rightnode){
        return (leftnode+1);
    }
    else{
        return (rightnode+1);
    }
}
int countnumberofnodes(Node *root){
    if (root == nullptr){
        return 0;
    }
     
    int leftnode = countnumberofnodes(root->left);
    int rightnode = countnumberofnodes(root->right);
    return (leftnode + rightnode+1);
    

}
int main(){
    Node *root=NULL;
    root = insertBST(root,7);
    insertBST(root, 5);
    insertBST(root, 4);
    insertBST(root, 13);
    insertBST(root,11);
    insertBST(root,19);
    deleteNode(root,5);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    int a=height(root);
    cout<<a<<endl;
    int b=countnumberofnodes(root);
    cout<<b<<endl;

    
}