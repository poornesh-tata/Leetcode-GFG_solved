//{ Driver Code Starts
// C program to find the mirror Node in Binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

 
// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int findMirror(Node *root, int target)
    {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int count=0; bool flag=false; int z=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<pair<int,int>> v;
            while(size--)
            {
                Node* node=q.front().first;
                int x = q.front().second;
                v.push_back({node->data,x});
                q.pop();
                if(node->data == target)
                {
                    flag=true;
                    z=x;
                }
                if(node->left) q.push({node->left,2*x});
                if(node->right) q.push({node->right,2*x+1});
            }
            if(flag)
            {
                int val=pow(2,count)-z-1;
                for(int i=0;i<v.size();i++)
                {
                    if(v[i].second==val) return v[i].first;
                }
                return -1;
            }
            count++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
 int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int target;
        cin >> target;
        cin.ignore();
        Solution obj;
        int res = obj.findMirror(root, target);
        cout << res << "\n";
    }
    return 0;
}

// } Driver Code Ends