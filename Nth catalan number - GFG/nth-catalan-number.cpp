//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    long long mod = 1e9+7;
    int findCatalan(int n) 
    {
        //code here
        vector<int> dp(n+1,-1);
        dp[0]=1; dp[1]=1;
        int ans = 0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i/2;j++)
            {
                ans += (dp[j-1]%mod*dp[i-j]%mod)%mod;
                ans%=mod;
            }

            if(i%2!=0)
            {
                int temp = i/2+1;
                dp[i]=(dp[temp-1]%mod*dp[i-temp]%mod)%mod;
                dp[i]+=(ans+ans)%mod;
                dp[i]=dp[i]%mod;
            }
            else dp[i]=(ans+ans)%mod;
            
            ans = 0;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends