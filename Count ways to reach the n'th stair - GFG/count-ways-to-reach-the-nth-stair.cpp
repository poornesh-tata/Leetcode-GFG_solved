//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    long long mod = 1e9+7;
    int fun(int n,vector<int>& dp)
    {
        if(n==0) return 1;
        int count=0;
        
        if(dp[n-1]!=-1) count+=dp[n-1]%mod;
        else count+=fun(n-1,dp)%mod;
        if(n>1)
        {
            if(dp[n-2]!=-1) count+=dp[n-2]%mod;
            else count+=fun(n-2,dp)%mod;
        }
        return dp[n]=count%mod;
    }
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends