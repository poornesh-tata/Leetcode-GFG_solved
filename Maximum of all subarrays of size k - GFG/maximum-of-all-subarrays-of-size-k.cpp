//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        /*This was code which was better than brute force but i has O(n*2) time complexity
        in worst case.
        Below there is another solution where we use deque which is optimised solution */
        
        // vector<int> v;
        // int maax=arr[0];
        // for(int i=1;i<k;i++)
        // {
        //     maax=max(arr[i],maax);
        // }
        // v.push_back(maax);
        // for(int i=k;i<n;i++)
        // {
        //     if(arr[i]>=maax) maax=arr[i];
        //     else if(arr[i-k]==maax)
        //     {
        //         maax=arr[i-k+1];
        //         for(int j=i-k+2;j<=i;j++)
        //         {
        //             maax=max(arr[j],maax);
        //         }
        //     }
        //     v.push_back(maax);
        // }
        // return v;
        
        vector<int> ans;
        deque<pair<int,int>> dq;
        for(int i=0;i<k;i++)
        {
            if(dq.empty()) dq.push_back({arr[i],i});
            else if(dq.back().first<arr[i])
            {
                while(!dq.empty() and dq.back().first<arr[i])
                {
                    dq.pop_back();
                }
                dq.push_back({arr[i],i});
            }
            else dq.push_back({arr[i],i});
        }
        ans.push_back(dq.front().first);
        for(int i=k;i<n;i++)
        {
            if(dq.empty()) dq.push_back({arr[i],i});
            else if(dq.back().first<arr[i])
            {
                while(!dq.empty() and dq.back().first<arr[i])
                {
                    dq.pop_back();
                }
                dq.push_back({arr[i],i});
            }
            else dq.push_back({arr[i],i});
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
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends