//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i = N-1;
        for(i;i>0;i--)
        {
            if(arr[i]>arr[i-1]) break;
        }
        // cout<<i<<endl;
        if(i<=0)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        priority_queue<pair<int,int>> pq1,pq2;
        pq1.push({arr[i-1],i-1});
        for(int j=i;j<N;j++)
        {
            if(arr[j]>arr[i-1]) pq1.push({arr[j],j});
            if(arr[j]>arr[i]) pq2.push({arr[j],j});
            if(pq1.size()>2) pq1.pop();
            if(pq2.size()>2) pq2.pop();
        }
        if(pq2.size()<2)
        {
            auto x = pq1.top(); pq1.pop();
            auto y = pq1.top(); pq1.pop();
            // cout<<x.second<<" "<<y.second<<" 1"<<endl;
            swap(arr[x.second],arr[y.second]);
            sort(arr.begin()+i,arr.end());
        }
        else
        {
            auto x = pq2.top(); pq2.pop();
            auto y = pq2.top(); pq2.pop();
            // cout<<x.second<<" "<<y.second<<" 2"<<endl;
            swap(arr[x.second],arr[y.second]);
            sort(arr.begin()+i+1,arr.end());
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends