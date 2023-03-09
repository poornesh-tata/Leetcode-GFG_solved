//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1\n";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends


/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

//Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    TreeNode* main; TreeNode* lnode; TreeNode* rnode; queue<TreeNode*> q;
    
    Node* start=head; Node* left=head; Node* right=head;
    
    if(head->next) left=head->next;
    else
    {
        main=new TreeNode(start->data);
        root=main;
        return ;
    }
    if(head->next->next) right=head->next->next;
    else
    {
        main=new TreeNode(start->data);
        lnode=new TreeNode(left->data);
        root=main;
        main->left=lnode;
        return ;
    }
    bool flag=true; 
    
    while(right)
    {
        if(flag)
        {
            main=new TreeNode(start->data);
            q.push(main);
            root=main;
            flag=false;
        }
        else
        {
            main=q.front();
        }
        
        lnode=new TreeNode(left->data);
        q.push(lnode);
        rnode=new TreeNode(right->data);
        q.push(rnode);
        
        main->left=lnode;
        main->right=rnode;
        
        if(left->next and left->next->next) left=left->next->next;
        else left=NULL;
        if(right->next and right->next->next) right=right->next->next;
        else right=NULL;

        q.pop();
    }
    if(left and q.back()->data!=left->data)
    {
        main=q.front();
        lnode=new TreeNode(left->data);
        main->left=lnode;
    }
}
