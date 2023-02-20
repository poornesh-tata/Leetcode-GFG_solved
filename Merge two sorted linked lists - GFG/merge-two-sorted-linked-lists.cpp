//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node*l1=NULL,*l2=NULL,*d1=NULL,*d=NULL,*temp=NULL,*start=NULL,*dummy=NULL;
    
    if(head1->data<=head2->data)
    {
        l1=head1;
        l2=head2;
    }
    else
    {
        l2=head1;
        l1=head2;
    }
    start=l1;

    while(l1 and l2)
    {
        while(l1 and l1->data<=l2->data)
        {
            d=l1;
            l1=l1->next;
        }
        d1=l2;
        if(l1==NULL) continue;
        while(l2 and l2->data<=l1->data)
        {
            dummy=l2;
            l2=l2->next;
        }
        d->next=d1;
        dummy->next=l1;
        
    }
    if(l2!=NULL) d->next=l2;
    
    return start;
}  