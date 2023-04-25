//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        priority_queue<int> pq(arr.begin(),arr.end());
        
        long long sum=0;
        for(auto it:arr) sum+=it;
        
        unordered_map<int,long long> hash;
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            sum-=x;
            hash[x]=sum;
        }
        
        vector<long long> ans;
        for(auto it:arr)
        {
            ans.push_back(hash[it]);
        }
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends