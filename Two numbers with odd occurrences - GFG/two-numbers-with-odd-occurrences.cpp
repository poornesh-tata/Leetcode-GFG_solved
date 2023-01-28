//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int nums[], long long int N)  
    {
        // code here
        int x=0;
        for(int i=0;i<N;i++) x=x^nums[i];
        
        int a=1;
        while(!(x&a))
        {
            a=a<<1;
        }
        int l=0,r=0;
        for(int i=0;i<N;i++)
        {
            if(nums[i]&a)
            {
                l=l^nums[i];
            }
            else
            {
                r=r^nums[i];
            }
        }
        return {max(l,r),min(l,r)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends