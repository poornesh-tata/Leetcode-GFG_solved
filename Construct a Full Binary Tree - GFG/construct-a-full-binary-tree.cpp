//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

Node* constructBinaryTree(int pre[], int preMirror[], int size);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
Node* fun(int l,int r,int pre[])
{
    int mid=(l+r)/2;
    Node* root=new Node(pre[l]);
    if(l<r)
    {
        root->left=fun(l+1,mid,pre);
        root->right=fun(mid+1,r,pre);
    }
    return root;
}
Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
    return fun(0,size-1,pre);
}