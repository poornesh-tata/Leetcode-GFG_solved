//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        // your code here
        if(k==1) return nums;
        vector<int> ans;
        deque<pair<int,int>> dq;
        for(int i=0;i<k;i++)
        {
            if(dq.empty()) dq.push_back({nums[i],i});
            else if(dq.back().first<nums[i])
            {
                while(!dq.empty() and dq.back().first<nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back({nums[i],i});
            }
            else dq.push_back({nums[i],i});
        }
        ans.push_back(dq.front().first);
        for(int i=k;i<n;i++)
        {
            if(dq.empty()) dq.push_back({nums[i],i});
            else if(dq.back().first<nums[i])
            {
                while(!dq.empty() and dq.back().first<nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back({nums[i],i});
            }
            else dq.push_back({nums[i],i});
            while(dq.front().second<=(i-k)) dq.pop_front();
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends