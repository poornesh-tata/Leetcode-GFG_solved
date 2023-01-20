//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> nums, int N) {
        // Code here
        unordered_set<int> s(nums.begin(),nums.end());
        map<int,int> hash;
        for(auto it:nums) hash[it]++;
        int count=0;
        int maxi=0;
        for(auto it:hash)
        {
            if(it.second<=1) continue;
            int dup= it.second-1;
            maxi=max(it.first+1,maxi);
            while(dup)
            {
                if(s.find(maxi)==s.end())
                {
                    count+=(maxi-it.first);
                    dup--;
                    s.insert(maxi);
                }
                maxi++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends