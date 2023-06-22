//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fun(int i, int j, vector<vector<int>>& points, int n, vector<vector<int>>& dp)
    {
        if(i==n) return 0;
        int maxi = INT_MIN;
        for(int k=0;k<3;k++)
        {
            if(k != j)
            {
                int x;
                if(dp[i+1][k]!=-1) x = dp[i+1][k]+points[i][j];
                else x = fun(i+1,k,points,n,dp)+points[i][j];
                maxi=max(maxi,x);
            }
        }
        return dp[i][j] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n+1, vector<int>(3,-1));
        int maxi = INT_MIN;
        for(int i=0;i<3;i++)
        {
            maxi = max(maxi,fun(0,i,points,n,dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends