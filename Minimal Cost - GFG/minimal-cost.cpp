//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int j,vector<int>& height,int k,vector<int>& dp)
    {
        int min_steps=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            if(j+i < height.size())
            {
                int z=0;
                if(dp[j+i]!=-1) z=dp[j+i];
                else z=fun(j+i,height,k,dp);
                
                int steps = z + abs(height[j]-height[i+j]);
                min_steps=min(min_steps,steps);
            }
            else break;
        }
        return dp[j]=(min_steps==INT_MAX?0:min_steps);
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1,-1);
        return fun(0,height,k,dp);
        
        // for(auto it:dp) cout<<it<<" ";
        // cout<<endl;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends