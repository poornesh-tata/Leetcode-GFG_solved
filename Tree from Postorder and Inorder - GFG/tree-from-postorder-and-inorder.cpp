//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* fun(Node* root, int in[],int post[],int n)
{
    if(n<=0) return NULL;
    root->data=post[n-1];
    int i=0;
    for(i=0;i<n;i++) if(in[i]==post[n-1]) break;
    
    if(i==0) root->left=NULL;
    if(i==n-1) root->right=NULL;
    
    int leftin[i]; int leftpost[i]; int rightin[n-i-1]; int rightpost[n-i-1];
    for(int j=0;j<i;j++)
    {
        leftin[j]=in[j];
        leftpost[j]=post[j];
    }
    for(int j=0;j<n-i-1;j++)
    {
        rightin[j]=in[j+i+1];
        rightpost[j]=post[j+i];
    }
    
    Node* left = new Node(-1);
    root->left = fun(left,leftin,leftpost,i);
    Node* right = new Node(-1);
    root->right = fun(right,rightin,rightpost,n-i-1);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    Node* root=new Node(-1);
    return fun(root,in,post,n);
}
