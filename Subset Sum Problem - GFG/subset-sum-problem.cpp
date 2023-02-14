//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int i,int s,int sum,vector<int> &arr,vector<vector<int>>&dp)
    {
        if(s==sum) return 1;
        if(i>=arr.size())
        {
            if(s==sum)
            {
                return 1;
            }
            return 0;
        }
        if(s>sum) 
        {
            return 0;
        }
        if(dp[i][s]!=-1)return dp[i][s];
         bool npick=f(i+1,s,sum,arr,dp);
         bool pick=0;
         if(s+arr[i]<=sum)
         {
             pick=f(i+1,s+arr[i],sum,arr,dp);
         }
         return dp[i][s]=(pick or npick);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int s=0;
        vector<vector<int> >dp(arr.size()+1,vector<int>(sum+1,-1));
        return f(0,s,sum,arr,dp);
    }
};

//User function template for C++

/*class Solution{   
public:
    bool f(int i,int s,int& sum,vector<int> &arr)
    {
        if(i>=arr.size())
        {
            if(s==sum)
            {
                return true;
            }
            return false;
        }
        if(s>sum) 
        {
            return false;
        }
        if(s==sum) return true;
        bool npick=f(i+1,s,sum,arr);
        bool pick=f(i+1,s+arr[i],sum,arr);
        return pick or npick; 
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int s=0;
        return f(0,s,sum,arr);
    }
};*/



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends