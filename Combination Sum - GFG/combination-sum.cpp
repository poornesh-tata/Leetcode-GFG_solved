//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void f(int i,int target,vector<int>&a,vector<int> v,vector<vector<int>> &ans)
    {
        if(i>=a.size())
        {
            if(target==0)
            {
                ans.push_back(v);
            }
            return;
        }
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(target>=a[i])
        {
            v.push_back(a[i]);
            f(i,target-a[i],a,v,ans);
            v.pop_back();
        }
        f(i+1,target,a,v,ans);
    }
    vector<vector<int> > combinationSum(vector<int> &a, int B) {
        // Your code here
        set<int> hash(a.begin(),a.end());
        a.clear();
        for(auto it:hash) a.push_back(it);
        
        vector<vector<int>> ans;
        vector<int> v;
        f(0,B,a,v,ans);
        // set<vector<int>> hash(ans.begin(),ans.end());
        // ans.clear();
        // for(auto it:hash) ans.push_back(it);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends