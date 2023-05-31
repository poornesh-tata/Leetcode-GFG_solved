//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++) hash[arr[i]]++;
        int freq=INT_MAX, ans=0;
        for(auto it:hash)
        {
            if(it.second<=freq)
            {
                freq=it.second;
            }
        }
        for(auto it:hash)
        {
            if(it.second==freq) ans=max(ans,it.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends