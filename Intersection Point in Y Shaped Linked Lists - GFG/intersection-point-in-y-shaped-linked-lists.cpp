//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
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

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        Node*ptr1=head1,*ptr2=head2;
        int c1=0,c2=0;
        while(ptr2)
        {
            ptr2=ptr2->next;
            c2++;
        }
        while(ptr1)
        {
            ptr1=ptr1->next;
            c1++;
        }
        int x=c1-c2; ptr1=head1,ptr2=head2;
        // Move pointer of greater length to c1-c2 positions ...
        // So moving both the pointers simultaneously makes both intersect each other if they have
        // intersection points else we return -1;
        if(x>0)
        {
            while(x--)
            {
                ptr1=ptr1->next;
            }
        }
        else
        {
            while(x++)
            {
                ptr2=ptr2->next;
            }
        }
        while(ptr1 and ptr2)
        {
            if(ptr1==ptr2) return ptr1->data;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return -1;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends