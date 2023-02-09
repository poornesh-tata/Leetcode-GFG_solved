//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long mod=1e9+7;
	int seq(int i,int arr[],int n,int sum,vector<vector<int>>&dp)
	{
	    if(i>=n)
	    {
	        if(sum==0)
	        {
	            //count++;
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[i][sum]!=-1)return dp[i][sum];
	    int right=(seq(i+1,arr,n,sum,dp))%mod;
	    int left=0;
	    if(sum>=arr[i])
	    {
	        left=(seq(i+1,arr,n,sum-arr[i],dp))%mod;
	    }
	    return dp[i][sum]=(left+right)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return seq(0,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends