//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &n) {
        // code here
        vector<vector<int>> ans;
        int i=0,size=intervals.size();
        while(i<size and intervals[i][0]<n[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        if(i==0)
        {
            ans.push_back(n);
        }
        if(ans.back()[1]>=n[0])
        {
            vector<int> v=ans.back();
            ans.pop_back();
            int maxi=max(v[1],n[1]);
            ans.push_back({v[0],maxi});
        }
        else ans.push_back(n);
        for(i;i<size;i++)
        {
            while(i<size and intervals[i][0]<=ans.back()[1])
            {
                vector<int> v=ans.back();
                ans.pop_back();
                int maxi=max(v[1],intervals[i][1]);
                ans.push_back({v[0],maxi});
                i++; 
            }
            if(i<size) ans.push_back(intervals[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends