//{ Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* fun(Node* root,int in[],int pre[], int n)
    {
        if(n<=0) return NULL;
        root->data=pre[0];
        int i=0;
        for(i;i<n;i++) if(in[i]==pre[0]) break;
        
        if(i==0) root->left=NULL;
        if(i==n-1) root->right=NULL;
        
        int leftin[i]; int leftpre[i]; int rightin[n-i-1]; int rightpre[n-i-1];
        
        for(int j=0;j<i;j++)
        {
            leftin[j]=in[j]; // cout<<leftin[j]<<" ";
        }
        for(int j=0;j<i;j++)
        {
            leftpre[j]=pre[j+1]; // cout<<leftpre[j]<<" ";
        }

        for(int j=0;j<n-i-1;j++)
        {
            rightin[j]=in[i+1+j]; // cout<<rightin[j]<<" ";
        }
        for(int j=0;j<n-i-1;j++)
        {
            rightpre[j]=pre[j+i+1]; // cout<<rightpre[j]<<" ";
        }

        Node* left=new Node(-1);
        root->left = fun(left,leftin,leftpre,i);
        
        Node* right=new Node(-1);
        root->right = fun(right,rightin,rightpre,n-i-1);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* root=new Node(-1);
        return fun(root,in,pre,n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends