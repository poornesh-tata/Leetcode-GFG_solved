//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>> dp(N+1,vector<int>(6,INT_MAX));
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<3;j++)
            {
                if(i==N-1)
                {
                    dp[i][j]=colors[i][j];
                    continue;
                } 
                for(int k=0;k<3;k++)
                {
                    if(k!=j)
                    {
                        dp[i][j]=min(dp[i][j],dp[i+1][k]);   
                    }
                }
                dp[i][j]+=colors[i][j];
                
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<3;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends