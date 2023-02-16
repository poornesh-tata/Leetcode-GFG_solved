//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int goodStones(int n,vector<int> &arr){
        // Code here
        unordered_set<int> hash;
        vector<int> dp(n,-1);
        int ans=0;
        for(int i=dp.size()-1;i>=0;i--)
        {
            if(arr[i]==0)
            {
                dp[i]=0;
                continue;
            }
            int x=i+arr[i];
            if(x<0 or x>=n)
            {
                dp[i]=1;
                continue;
            }
            if(dp[x]!=-1)
            {
                dp[i]=dp[x];
                continue;
            }
            hash.insert(i);
            while(true)
            {
                if(hash.find(x)!=hash.end())
                {
                    for(auto it:hash)
                    {
                        dp[it]=0;
                    }
                    break;
                }
                if(x<0 or x>=n)
                {
                    for(auto it:hash)
                    {
                        dp[it]=1;
                    }
                    break;
                }
                if(dp[x]!=-1)
                {
                    for(auto it:hash)
                    {
                        dp[it]=dp[x];
                    }
                    break;
                }
                hash.insert(x);
                x=x+arr[x];
            }
            hash.clear();
        }
        for(auto it:dp)
        {
            // cout<<it<<" ";
            if(it>0) ans++;
        }
        // cout<<endl;
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends