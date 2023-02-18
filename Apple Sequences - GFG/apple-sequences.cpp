//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int i=0,j=0,count=0,ans=INT_MIN;
        while(i<n and j<n)
        {
            if(arr[j]=='O')
            {
                count++;
            }
            if(count>m)
            {
                ans=max(ans,j-i);
                while(arr[i]=='A')
                {
                    i++;
                }
                i++;
                count--;
            }
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends