//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    void kdist(Node* root, int k, int& ans)
    {
        if(root==NULL or k<0) return ;
        ans+=root->data; //cout<<root->data<<endl;
        if(k==0)
        {
            return ;
        }
        if(root->left) kdist(root->left,k-1,ans);
        if(root->right) kdist(root->right,k-1,ans);
    }
    void fun(Node* root,int k, int target,int& ans,int& temp)
    {
        if(root==NULL) return ;
        if(root->data==target)
        {
            kdist(root,k,ans);
            temp--;
            return;
        }
        
        if(temp==k) if(root->left) fun(root->left,k,target,ans,temp);
        if(temp!=k)
        {
            if(temp>=0) ans+=root->data; //cout<<root->data<<endl;
            if(temp==0)
            {
                temp--;
                return ;
            }
            kdist(root->right,temp-1,ans);
            temp--;
            return ;
        }

        if(temp==k) if(root->right) fun(root->right,k,target,ans,temp);
        if(temp!=k)
        {
            if(temp>=0) ans+=root->data; //cout<<root->data<<endl;
            if(temp==0)
            {
                temp--;
                return ;
            }
            kdist(root->left,temp-1,ans);
            temp--;
            return ; 
        }
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        int ans=0;
        fun(root,k,target,ans,k);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends