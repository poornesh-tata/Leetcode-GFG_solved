/*
QUESTION :- LEETCODE 2130
=========================
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/


int pairSum(ListNode* head) {
        // THIS SOLUTION WAS DONE BY REVERSING SECOND HALF OF THE LINKEDLIST
        
        ListNode*slow=head,*fast=head->next;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* start=slow->next, *prev=NULL, *forward=NULL;
        while(start)
        {
            forward=start->next;
            start->next=prev;
            prev=start;
            start=forward;
        }
        slow->next=prev;
        slow=head;
        int ans=INT_MIN;
        while(prev)
        {
            ans=max(ans,slow->val+prev->val);
            slow=slow->next;
            prev=prev->next;
        }
        return ans;

        // NAIVE APPROACH USING EXTRA SPACE LIKE VECTORS AND DOING CALCULATIONS

        // vector<int> v;
        // ListNode* ptr=head;
        // while(ptr)
        // {
        //     v.push_back(ptr->val);
        //     ptr=ptr->next;
        // }
        // int n = v.size(); int ans=INT_MIN;
        // for(int i=0;i<n/2;i++)
        // {
        //     ans=max(ans,v[i]+v[n-i-1]);
        // }
        // return ans;
    }
