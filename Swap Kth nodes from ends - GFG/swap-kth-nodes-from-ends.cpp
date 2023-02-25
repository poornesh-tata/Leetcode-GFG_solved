//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
        
    bool f=true;
    
    for(int i=0; i<num; i++){
        if((i==K-1) || (i==num - K)){
            if(!((before[K-1] == after[num - K]) && (before[num-K] == after[K-1]))) f=0;
        }
        else{
            if(before[i] != after[i]) f=0;
        }
    }
    
    return f;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int k)
{
    // Your Code here
    Node*start=head,*end=head,*ptr=head,*ep=head,*sp=head;
    
    // Place  start and end pointers at respective positions
    int temp=k;
    while(--temp and start)
    {
        sp=start;
        start=start->next;
    }
    if(start==NULL) return head;
    temp=k;
    ptr=head;
    while(temp--)
    {
        ptr=ptr->next;
    }
    while(ptr)
    {
        ep=end;
        ptr=ptr->next;
        end=end->next;
    }
    // Base cases where start==end or start and end lies side by each other.
    if(start==end) return head;
    else if(start==ep)
    {
        sp->next=end->next;
        end->next=NULL;
        start->next=NULL;
        
        end->next=sp->next;
        sp->next=end;
        ep=end;
        end=end->next;
        start->next=end;
        ep->next=start;
        
        return head;
    }
    else if(end==sp)
    {
        ep->next=start->next;
        end->next=NULL;
        start->next=NULL;
        
        start->next=ep->next;
        ep->next=start;
        sp=start;
        start=start->next;
        end->next=start;
        sp->next=end;
    
        return head;
    }
    
    // cout<<start->data<<" "<<end->data<<endl;
    // Make start and end pointers seperate from ll
    if(end==head)
    {
        head=end->next;
        end->next=NULL;
    }
    else
    {
        ep->next=end->next;
        end->next=NULL;
    }
    if(start==head)
    {
        head=start->next;
        start->next=NULL;
    }
    else
    {
        sp->next=start->next;
        start->next=NULL;
    }
    
    // insert start at end and end at start.
    if(sp==start)
    {
        end->next=head;
        head=end;
    }
    else
    {
        end->next=sp->next;
        sp->next=end;
    }
    
    if(ep==end)
    {
        start->next=head;
        head=start;
    }
    else
    {
        start->next=ep->next;
        ep->next=start;
    }
    
    return head;
}
