//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans=INT_MIN,p=1;
	    for(auto it:arr)
	    {
	        p=p*it;
	        ans=max(ans,p);
	        if(it==0)
	        {
	            p=1;
	        }
	    }
	    p=1;
	    long long a=INT_MIN;
	    for(int i=arr.size()-1;i>=0;i--)
	    {
	        p=p*arr[i];
	        ans=max(ans,p);
	        if(arr[i]==0)
	        {
	            p=1;
	        }
	    }
	    return max(ans,a);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends