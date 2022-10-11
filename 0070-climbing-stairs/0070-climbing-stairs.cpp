class Solution {
public:
    int climbStairs(int n) {
        // Tabulation
        // vector<int> dp(n+1,-1);
        // dp[1]=1;
        // dp[2]=2;
        // for(int i=3;i<dp.size();i++)
        // {
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        
        // Tabulation without extra space
        if(n<3) return n;
        int a=1;
        int b=2;
        int c;
        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};