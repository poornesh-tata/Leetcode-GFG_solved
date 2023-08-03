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
        if(i<=0)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        priority_queue<pair<int,int>> pq;
        for(int j=i;j<N;j++)
        {
            if(arr[j]>arr[i-1]) pq.push({arr[j],j});
            if(pq.size()>1) pq.pop();
        }
        auto x = pq.top(); pq.pop();
        swap(arr[i-1],arr[x.second]);
        sort(arr.begin()+i,arr.end());
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