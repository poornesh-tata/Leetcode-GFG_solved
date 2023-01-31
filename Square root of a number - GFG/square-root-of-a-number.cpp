//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        if(x==0 or x==1) return x;
        long long low =0;
        long long high =x;
        long long mid=(low+high)/2;
        long long ans=0;
        while(low<=high)
        {
            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid>x)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
                ans=mid;
            }
            mid=(low+high)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends