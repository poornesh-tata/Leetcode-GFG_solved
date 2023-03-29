//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int c=0; int s=0; int l=0; int n=S.size();
        for(int i=0;i<n;i++)
        {
            s=0,l=0;
            for(int j=i;j<n;j++)
            {
                if(islower(S[j])) s++;
                else l++;
                if(s==l) c++;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends