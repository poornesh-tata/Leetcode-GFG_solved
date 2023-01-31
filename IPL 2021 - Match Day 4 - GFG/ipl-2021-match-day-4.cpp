//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int n)
    {
        // Your code here
        int res=0;
        for(int i=31;i>=0;i--)
        {
            int check = res | (1<<i);
            int count=0;
            for(int j=0;j<n;j++)
            {
                if( (arr[j]&check)==check)
                {
                    count++;
                }
            }
            if(count>1)
            {
                res=res|(1<<i);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends