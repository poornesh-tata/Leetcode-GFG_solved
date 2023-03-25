//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void dfs(Node* root, int sum,int &s,int &ans)
    {
        if(root->left==NULL and root->right==NULL)
        {
            ans=max(ans,sum-s);
            return ;
        }
        if(root->right)
        {
            s+=root->right->data;
            dfs(root->right,sum,s,ans);
            s-=root->right->data;
        }
        if(root->left)
        {
            s+=root->left->data;
            dfs(root->left,sum,s,ans);
            s-=root->left->data;
        }
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        if(root->left==NULL and root->right==NULL and root->data!=target)
        {
            return -1;
        }
        if(root->left==NULL and root->right==NULL)
        {
            return 0;
        }

        Node* node=root; int sum=0;
        while(node->data!=target)
        {
            // if(node->left==NULL and node->right==NULL) return -1;
            if(node->data<target )
            {
                if(node->right)
                {
                    sum+=node->data;
                    node=node->right;
                }
                else return -1;
            }
            else if(node->data>target )
            {
                if(node->left)
                {
                    sum+=node->data;
                    node=node->left;
                }
                else return -1;
            }
        }
        
        int ans = INT_MIN; int s=0;
        dfs(node,sum,s,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends