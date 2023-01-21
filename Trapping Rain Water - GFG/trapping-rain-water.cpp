//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> maxl;
        vector<int> maxr;
        maxl.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            maxl.push_back(max(arr[i],maxl[i-1]));
        }
        maxr.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            maxr.push_back(max(arr[i],maxr.back()));
        }
        reverse(maxr.begin(),maxr.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(maxl[i],maxr[i])-arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends