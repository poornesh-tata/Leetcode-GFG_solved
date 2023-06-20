//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long mod=1e9+7;
    long long fun(int n,vector<long long>& dp)
    {
        if(n==0 or n==1) return dp[n]=n;
        if(dp[n]!=-1) return dp[n]%mod;
        return dp[n]=(fun(n-1,dp) + fun(n-2,dp))%mod;
    }
    long long int topDown(int n) {
        // code here
        vector<long long> dp(n+1,-1);
        return fun(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        if(n==0 or n==1) return n;
        int a=0,b=1,c=0;
        while(n-1)
        {
            c=(a+b)%mod;
            a=b;
            b=c;
            n--;
        }
        return c%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends