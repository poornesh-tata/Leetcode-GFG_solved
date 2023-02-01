//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int nums[] ,int N) {
        // int ans=0;
        // int b[32]={0};
        // for(int i=0;i<N;i++)
        // {
        //     int p=0;
        //     int num=nums[i];
        //     while(num)
        //     {
        //         if(num&1)
        //         {
        //             b[p]++;
        //         }
        //         num=num>>1;
        //         p++;
        //     }
        // }
        // for(int i=0;i<32;i++)
        // {
        //     if(b[i]%3!=0)
        //     {
        //         ans|=(1<<i);
        //     }
        // }
        // return ans;
        /* The above solution only works for positive integers */
        
        unordered_set<int> s(nums,nums+N);
        int arr_sum = accumulate(nums,nums+N, 0);
        int set_sum = accumulate(s.begin(), s.end(), 0);
        return (3 * set_sum - arr_sum) / 2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends