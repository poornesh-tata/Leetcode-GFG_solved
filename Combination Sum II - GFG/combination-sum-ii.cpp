//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void f(int index,int target,vector<int> v,vector<int>& arr,vector<vector<int>>& ans)
    {
        if(index>=arr.size())
        {
            if(target==0) ans.push_back(v);
            return ;
        }
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        unordered_set <int> hash;
        for(int i=index;i<arr.size();i++)
        {
            if(hash.find(arr[i])==hash.end())
            {
                if(target>=arr[i])
                {
                    hash.insert(arr[i]);
                    v.push_back(arr[i]);
                    f(i+1,target-arr[i],v,arr,ans);
                    v.pop_back();
                }
                else break; 
                /* Elements are sorted and next elements will be >= present element
                    so no need of checking again. */
            }
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int target)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> v;
        f(0,target,v,arr,ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends