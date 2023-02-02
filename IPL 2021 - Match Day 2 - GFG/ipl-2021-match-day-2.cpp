//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> v;
        int maax=arr[0];
        for(int i=1;i<k;i++)
        {
            maax=max(arr[i],maax);
        }
        v.push_back(maax);
        for(int i=k;i<n;i++)
        {
            if(arr[i]>=maax) maax=arr[i];
            else if(arr[i-k]==maax)
            {
                maax=arr[i-k+1];
                for(int j=i-k+2;j<=i;j++)
                {
                    maax=max(arr[j],maax);
                }
            }
            v.push_back(maax);
        }
        return v;
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