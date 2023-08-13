//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int fun(int start, int end, string s, set<string>& hash,vector<vector<int>>& dp)
    {
        if(start >= s.size()) return true;
        string str = "";
        for(int i=start;i<=end;i++)
        {
            str+=s[i];
            if(dp[start][i]!=-1) return dp[start][i];
            if(hash.find(str)!=hash.end())
            {
                dp[start][i]=1;
                dp[i+1][end] = fun(i+1,end,s,hash,dp);
            }
            else dp[start][i]=0;
        }
        return dp[start][end];
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        set<string> hash(B.begin(),B.end());
        int n = A.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        fun(0,n-1,A,hash,dp); 
        return dp[n][n-1]==-1?false:dp[n][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends