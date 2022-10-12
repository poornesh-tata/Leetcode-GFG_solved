class Solution {
public:
    int f(int n,vector<int>& dp)
    {
        if(n%2==0)
        {
            return dp[n/2];
        }
        else return dp[n/2]+dp[(n/2)+1];
    }
    int getMaximumGenerated(int n) {
        if(n==0 or n==1) return n;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        for(int i=2;i<=n;i++)
        {
            dp.push_back(f(i,dp));
        }
        int max=INT_MIN;
        for(auto it:dp)
        {
            if(it>max) max=it;
        }
        return max;
    }
};