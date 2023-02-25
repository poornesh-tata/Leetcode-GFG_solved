//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL) return head;
        Node*even=head,*ptr=head,*pre=head,*dummy=NULL;
        if(even->data%2==0)
        {
            while(even->next and even->data%2==0)
            {
                pre=even;
                even=even->next;
            }
            even=pre;
            ptr=even->next;
        }
        while(ptr and ptr->next)
        {
            while(ptr->next and ptr->data%2!=0)
            {
                pre=ptr;
                ptr=ptr->next;
            }
            if(ptr->data%2!=0) break;
            if(even==head and even->data%2!=0)
            {
                pre->next=ptr->next;
                ptr->next=NULL;
                head=ptr;
                ptr->next=even;
                even=ptr;
                ptr=pre;
            }
            else 
            {
                pre->next=ptr->next;
                ptr->next=NULL;
                dummy=even->next;
                even->next=ptr;
                ptr->next=dummy;
                even=even->next;
                ptr=pre;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends