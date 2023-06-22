//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int fun(int i, int j, int a, int b, vector<vector<int>>& dp)
    {
        if(i==a-1 and j==b-1) 
        {
            dp[i][j]=1;
            return 1;
        }
        if(i>=a or j>=b) return 0;
        
        int x,y;
        if(dp[i+1][j]!=-1) x = dp[i+1][j];
        else x = fun(i+1,j,a,b,dp);
        if(dp[i][j+1]!=-1) y = dp[i][j+1];
        else y = fun(i,j+1,a,b,dp);
        
        return dp[i][j] = x+y;
    }  
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        fun(0,0,a,b,dp);
        return dp[0][0];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends