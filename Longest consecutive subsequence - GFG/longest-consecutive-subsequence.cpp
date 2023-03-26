//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
      //Your code here
      
        unordered_set<int> hash(nums,nums+n); int ans=INT_MIN;
        for(auto it:hash)
        {
            if(hash.find(it-1)==hash.end())
            {
                int x=it; int count=0;
                while(hash.find(x)!=hash.end())
                {
                    count++;
                    x++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
        
      
        // O(N*logN)+O(N) == O(N*logN)
        
        // if(n==0) return 0;
        // sort(nums,nums+n); int ans=INT_MIN; int count=0;
        // for(int i=0;i<n-1;i++)
        // {
        //     if(nums[i]==nums[i+1]) continue;
        //     if(nums[i]==nums[i+1]-1)
        //     {
        //         count++;
        //     }
        //     else
        //     {
        //         ans=max(ans,count+1);
        //         count=0;
        //     }
        // }
        // ans=max(ans,count+1);
        // return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends